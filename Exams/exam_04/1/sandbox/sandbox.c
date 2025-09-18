// sandbox.c
// Execução protegida de uma função com limite de tempo (timeout) em processo filho.
// A ideia: executar a função "f" num fork separado, impor um alarm() (timeout) e
// analisar como o filho terminou (sucesso, erro, sinal ou timeout) retornando um
// código simples para o chamador.
//
// Retornos da função sandbox():
//  1  -> função terminou normalmente (exit code 0)
//  0  -> função "ruim" (timeout, sinal recebido ou exit code != 0)
// -1  -> erro interno (ex: falha no fork ou wait inesperado)
//
// Parâmetros:
//  f        -> ponteiro para função void(void) a ser executada no filho
//  timeout  -> segundos máximos permitidos
//  verbose  -> se true, imprime mensagens detalhadas
//
// Observação: usa alarm() + waitpid(). Para capturar timeout no processo pai
// instalamos um handler de SIGALRM "inócuo" que simplesmente interrompe waitpid.

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

// Handler vazio: apenas faz com que sinais (SIGALRM) interrompam syscalls bloqueantes
// sem encerrar o processo pai. Evita terminar o programa principal quando o timeout expira.
static void do_nothing(int sig)
{
	(void)sig;
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid = fork(); // Cria processo filho para isolar a execução da função

	if (pid == -1) // Falha no fork
		return (-1);

	if (pid == 0) // Processo filho
	{
		alarm(timeout);   // Timeout local no filho (caso fique preso)
		f();               // Executa a função fornecida
		exit(0);           // Se chegou aqui consideramos sucesso (exit code 0)
	}

	// Processo pai: prepara para detectar timeout usando SIGALRM
	struct sigaction sa;
	sa.sa_handler = do_nothing; // Handler neutro apenas para interromper waitpid
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
	alarm(timeout); // Agenda alarme para interromper o wait se exceder tempo

	int st; // Status de saída do filho
	pid_t r = waitpid(pid, &st, 0); // Espera o filho terminar
	if (r == -1)
	{
		if (errno == EINTR) // waitpid interrompido por sinal (provavelmente SIGALRM -> timeout)
		{
			kill(pid, SIGKILL);      // Garante que o filho morra
			waitpid(pid, NULL, 0);    // Limpa o zumbi
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
			return (0); // Timeout => função ruim
		}
		return (-1); // Erro inesperado em waitpid
	}
	if (WIFEXITED(st)) // Filho terminou via exit()
	{
		int ex_code = WEXITSTATUS(st);
		if (ex_code == 0) // Sucesso
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		if (verbose)
			printf("Bad function: exited with code %d\n", ex_code);
		return (0); // Exit code != 0 => consideramos ruim
	}
	if (WIFSIGNALED(st)) // Filho terminou por sinal
	{
		if (WTERMSIG(st) == SIGALRM) // Alarme no filho (timeout interno)
		{
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
			return (0);
		}
		if (verbose)
			printf("Bad function: %s\n", strsignal(WTERMSIG(st))); // Outro sinal (ex: SIGSEGV)
		return (0);
	}
	return (-1); // Caso não caia em nenhum cenário esperado
}
