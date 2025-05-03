/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_pipe_approach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:51:40 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:52:17 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief catches user input for here doc.
 *
 * Generates readline loop, and writes input in command's
 * heredoc_pipe[1].
 * Input is expanded according to bash rules for here doc.
 *
 * @param del is delimiter for here doc.
 * @param rule if it is QUOTE it will expand input, otherwise it will not.
 *
 * @return void.
 */
void	catch_here_input(char *del, t_type rule)
{
	char	*line;
	t_shell	*shell;

	shell = get_shell();
	line = readline(">");
	while (line && strcmp(line, del))
	{
		if (rule != QUOTE)
			here_expander(&line);
		write(shell->heredoc_pipe[1], line, safe_strlen(line));
		write(shell->heredoc_pipe[1], "\n", 1);
		if (line)
			free(line);
		line = readline(">");
	}
	if (!line)
		printf("minishell: warning: here-document at line \
			1 delimited by end-of-file( wanted \'%s\')\n", del);
	else if (line)
		free(line);
}

/**
 * @brief Performs here doc according to bash rules.
 *
 * If sigint is received during here doc, the function returns a closed fd.
 *
 * @param del here doc delimeter;
 * @param rule if it is QUOTE it will expand input, otherwise it will not.
 *
 * @return file descriptor, type pipe, where here is stored.
 */
int	here_doc(char *del, t_type expansion_rule)
{
	t_shell	*shell;
	int		pid;

	shell = get_shell();
	if (!del)
		return (-1);
	if (pipe(shell->heredoc_pipe) == -1)
		return (-2);
	pid = fork();
	if (pid == 0)
	{
		close(shell->heredoc_pipe[0]);
		here_sigint();
		catch_here_input(del, expansion_rule);
		close(shell->heredoc_pipe[1]);
		close_all_fd_red();
		ms_exit(&shell, NULL);
	}
	close(shell->heredoc_pipe[1]);
	waitpid(pid, &(shell->last_exit_code), 0);
	shell->last_exit_code = WEXITSTATUS(shell->last_exit_code);
	if (shell->last_exit_code == 130)
		close(shell->heredoc_pipe[0]);
	return (shell->heredoc_pipe[0]);
}

/**
 * @brief Manages the creation of here documents for a single command.
 *
 * Iterates over the redirections of the command, and for each
 * HERE_DOC type, it generates a here document using `here_doc`.
 * If a previous here doc exists, its file descriptor is closed.
 * Also handles input file errors and SIGINT interruptions.
 *
 * @param cmd the command whose redirections are to be processed.
 * @param fd_hd pointer to the file descriptor where the here doc will
 *  be stored.
 *
 * @return 1 if successful, 0 if a SIGINT was received or an error occurred.
 */
static int	manage_command_hd(t_cmd *cmd, int *fd_hd)
{
	int	j;

	j = -1;
	while (cmd->redirections[++j])
	{
		if (cmd->redirections[j]->type == HERE_DOC)
		{
			if (*fd_hd != 0)
				close(*fd_hd);
			*fd_hd = here_doc(cmd->redirections[j]->str,
					cmd->redirections[j]->expansion_rule);
			if (infile_error(cmd))
				close(*fd_hd);
			if (get_shell()->last_exit_code == 130 || *fd_hd < 0)
				return (0);
		}
	}
	return (1);
}

/**
 * @brief Manages here documents for all commands in the shell.
 *
 * Iterates through all commands in the shell, and processes their
 * HERE_DOC redirections using `manage_command_hd`.
 * If no input file error occurs, assigns the here doc fd to the command.
 *
 * @param shell the main shell structure containing the list of commands.
 *
 * @return void.
 */
void	manage_hd(t_shell *shell)
{
	int	i;
	int	fd_hd;

	i = -1;
	while (shell->cmd[++i])
	{
		fd_hd = 0;
		if (!manage_command_hd(shell->cmd[i], &fd_hd))
			return ;
		if (!infile_error(shell->cmd[i]))
			shell->cmd[i]->input_fd = fd_hd;
	}
}
