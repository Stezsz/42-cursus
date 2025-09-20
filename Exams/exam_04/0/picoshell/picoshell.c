#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Implementa um mini shell que executa comandos em pipeline (cmd1 | cmd2 | cmd3...)
// cmds: array de arrays de strings, cada sub-array é um comando com seus argumentos
int	picoshell(char **cmds[])
{
	pid_t	pid;
	int		pipefd[2]; // Pipe para conectar stdout de um processo ao stdin do próximo
	int		prev_fd;   // File descriptor do pipe anterior (input do comando atual)
	int		status;    // Status de saída dos processos filhos
	int		exit_code; // Código de saída final
	int		i;

	prev_fd = -1;   // Primeiro comando não tem input de pipe
	exit_code = 0;  // Assume sucesso inicialmente
	i = 0;
	while (cmds[i]) // Para cada comando no pipeline
	{
		// Se há um próximo comando, cria pipe para conectá-los
		if (cmds[i + 1] && pipe(pipefd))
			return (1); // Erro ao criar pipe
		pid = fork(); // Cria processo filho para executar o comando
		if (pid == -1) // Erro no fork
		{
			if (cmds[i + 1]) // Se criou pipe, fecha os descritores
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			return (1);
		}
		if (pid == 0) // Processo filho
		{
			// Conecta input do comando ao pipe anterior (se existir)
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1) // Redireciona stdin
					exit(1);
				close(prev_fd); // Fecha descriptor original
			}
			// Conecta output do comando ao próximo pipe (se não for último comando)
			if (cmds[i + 1])
			{
				close(pipefd[0]); // Filho não precisa ler do pipe
				if (dup2(pipefd[1], STDOUT_FILENO) == -1) // Redireciona stdout
					exit(1);
				close(pipefd[1]); // Fecha descriptor original
			}
			execvp(cmds[i][0], cmds[i]); // Executa o comando
			exit(127); // Se execvp falha, sai com erro
		}
		// Processo pai: gerencia pipes e continua para próximo comando
		if (prev_fd != -1)
			close(prev_fd); // Fecha pipe anterior (não precisa mais)
		if (cmds[i + 1]) // Se não é o último comando
		{
			close(pipefd[1]); // Pai não escreve no pipe
			prev_fd = pipefd[0]; // Guarda lado de leitura para próximo comando
		}
		i++; // Próximo comando
	}
	// Aguarda todos os processos filhos terminarem
	while (wait(&status) != -1)
	{
		// Se algum processo terminou com erro, marca exit_code como 1
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			exit_code = 1;
	}
	return (exit_code); // Retorna 0 se tudo ok, 1 se houve erro
}


/* Test main

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
static int	count_cmds(int argc, char **argv)
{
	int	count = 1;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "|") == 0)
			count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

	int	cmd_count = count_cmds(argc, argv);
	char	***cmds = calloc(cmd_count + 1, sizeof(char **));
	if (!cmds)
		return (perror("calloc"), 1);

	int	i = 1, j = 0;
	while (i < argc)
	{
		int	len = 0;
		while (i + len < argc && strcmp(argv[i + len], "|") != 0)
			len++;
		cmds[j] = calloc(len + 1, sizeof(char *));
		if (!cmds[j])
			return (perror("calloc"), 1);
		for (int k = 0; k < len; k++)
			cmds[j][k] = argv[i + k];
		cmds[j][len] = NULL;
		i += len + 1;
		j++;
	}
	cmds[cmd_count] = NULL;

	int	ret = picoshell(cmds);

	// Clean up
	for (int i = 0; cmds[i]; i++)
		free(cmds[i]);
	free(cmds);

	return (ret);
}
*/
