#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

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
