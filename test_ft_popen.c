#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// Fixed ft_popen implementation
int	ft_popen(const char *file, char *const argv[], char type)
{
	int		pipefd[2];
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	if (pid == 0) // Processo Filho
	{
		if (type == 'r')
		{
			close(pipefd[0]); // Filho não lê do pipe
			if (dup2(pipefd[1], STDOUT_FILENO) == -1)
				exit(1); // Not allowed to use perror, just exit
			close(pipefd[1]);
		}
		else // type == 'w'
		{
			close(pipefd[1]); // Filho não escreve no pipe
			if (dup2(pipefd[0], STDIN_FILENO) == -1)
				exit(1);
			close(pipefd[0]);
		}
		execvp(file, argv);
		exit(1); // Se execvp falhar, sai com erro
	}
	// Processo Pai
	if (type == 'r')
	{
		close(pipefd[1]); // Pai não escreve
		return (pipefd[0]); // Retorna FD de leitura
	}
	// type == 'w'
	close(pipefd[0]); // Pai não lê
	return (pipefd[1]); // Retorna FD de escrita
}


// Test main from attachment
static void test_read(void)
{
    char *args[] = {"echo", "Ola42", NULL};
    int fd = ft_popen("echo", args, 'r');
    if (fd < 0) { perror("ft_popen r"); return; }
    char buf[128];
    ssize_t n = read(fd, buf, sizeof(buf)-1);
    if (n >= 0) {
        buf[n] = '\0';
        printf("[READ ] '%s'", buf); // echo adiciona \n
    }
    close(fd);
    wait(NULL); // Wait for the child to prevent it from becoming a zombie
}

static void test_write(void)
{
    char *args[] = {"cat", NULL};
    int fd = ft_popen("cat", args, 'w');
    if (fd < 0) { perror("ft_popen w"); return; }
    const char *msg = "PIPE_TEST\n";
    printf("[WRITE] Enviando para o cat: '%s'", msg);
    write(fd, msg, strlen(msg));
    close(fd); // Closing the pipe will cause cat to exit
    wait(NULL); // Wait for the cat process to finish
    printf("[WRITE] 'cat' finalizado.\n");
}

int main(void)
{
    printf("== ft_popen tester ==\n");
    test_read();
    test_write();
    if (ft_popen(NULL, NULL, 'r') == -1)
        printf("[INVAL] OK - argumentos invalidos retornam -1\n");
    else
        printf("[INVAL] FAIL - argumentos invalidos deveriam retornar -1\n");

    return 0;
}
