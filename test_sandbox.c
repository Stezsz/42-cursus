#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

// Fixed sandbox implementation
static void do_nothing(int sig)
{
	(void)sig;
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0) // Processo filho
	{
		// O alarme é responsabilidade do pai. O filho apenas executa a função.
		f();
		exit(0);
	}

	// Processo pai: prepara para detectar timeout usando SIGALRM
	struct sigaction sa;
	sa.sa_handler = do_nothing;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
	alarm(timeout); // Agenda alarme para interromper o wait se exceder tempo

	int st; // Status de saída do filho
	pid_t r = waitpid(pid, &st, 0); // Espera o filho terminar
	alarm(0); // DESATIVA O ALARME! O filho já terminou.

	if (r == -1)
	{
		if (errno == EINTR) // waitpid interrompido por SIGALRM (timeout)
		{
			kill(pid, SIGKILL);
			waitpid(pid, NULL, 0); // Limpa o zumbi
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
			return (0);
		}
		return (-1); // Erro inesperado em waitpid
	}
	if (WIFEXITED(st)) // Filho terminou via exit()
	{
		int ex_code = WEXITSTATUS(st);
		if (ex_code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		if (verbose)
			printf("Bad function: exited with code %d\n", ex_code);
		return (0);
	}
	if (WIFSIGNALED(st)) // Filho terminou por sinal
	{
		// Não precisamos mais checar SIGALRM aqui, pois o alarme do filho foi removido.
		// O timeout é tratado pela interrupção do waitpid.
		if (verbose)
			printf("Bad function: %s\n", strsignal(WTERMSIG(st)));
		return (0);
	}
	return (-1); // Should not be reached
}


// Test main from attachment
static void ok_function(void)
{
    // This function is now empty to avoid interleaving output
}

static void slow_function(void)
{
    sleep(3);
}

static void crash_function(void)
{
    int *p = NULL;
    *p = 42;
    (void)p;
}

static void exit_function(void)
{
    exit(42);
}

int main(void)
{
    printf("== sandbox tester ==\n\n");

    printf("--> Testing nice function:\n");
    int r1 = sandbox(ok_function, 2, true);
    printf("Result: %d (expected 1)\n\n", r1);

    printf("--> Testing slow function (timeout):\n");
    int r2 = sandbox(slow_function, 1, true);
    printf("Result: %d (expected 0)\n\n", r2);

    printf("--> Testing crash function (SIGSEGV):\n");
    int r3 = sandbox(crash_function, 2, true);
    printf("Result: %d (expected 0)\n\n", r3);

    printf("--> Testing non-zero exit function:\n");
    int r4 = sandbox(exit_function, 2, true);
    printf("Result: %d (expected 0)\n\n", r4);

    return 0;
}
