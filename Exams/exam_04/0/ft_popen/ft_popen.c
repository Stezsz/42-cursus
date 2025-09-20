#include <unistd.h>
#include <stdlib.h>

// Implementa uma versão simplificada do popen() - cria pipe para comunicação com processo filho
int	ft_popen(const char *file, char *const argv[], char type)
{
	// Valida parâmetros: arquivo, argumentos e tipo ('r' para leitura, 'w' para escrita)
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;

	int fd[2]; // Array de descritores: fd[0] = leitura, fd[1] = escrita

	pipe(fd); // Cria pipe bidirecional para comunicação entre processos
	if (type == 'r') // Tipo 'r': queremos LER a saída do comando
	{
		if (fork() == 0) // Processo filho
		{
			dup2(fd[1], STDOUT_FILENO); // Redireciona stdout para escrita do pipe
			close(fd[0]); // Fecha leitura (não precisamos no filho)
			close(fd[1]); // Fecha escrita original (agora é stdout)
			execvp(file, argv); // Executa comando - saída vai para o pipe
			exit (-1); // Se execvp falha, sai com erro
		}
		close(fd[1]); // Processo pai fecha escrita (só vai ler)
		return (fd[0]); // Retorna descriptor de leitura para o pai
	}
	if (type == 'w') // Tipo 'w': queremos ESCREVER para a entrada do comando
	{
		if (fork() == 0) // Processo filho
		{
			dup2(fd[0], STDIN_FILENO); // Redireciona stdin para leitura do pipe
			close(fd[0]); // Fecha leitura original (agora é stdin)
			close(fd[1]); // Fecha escrita (não precisamos no filho)
			execvp(file, argv); // Executa comando - entrada vem do pipe
			exit (-1); // Se execvp falha, sai com erro
		}
		close(fd[0]); // Processo pai fecha leitura (só vai escrever)
		return (fd[1]); // Retorna descriptor de escrita para o pai
	}
	return -1; // Tipo inválido
}
