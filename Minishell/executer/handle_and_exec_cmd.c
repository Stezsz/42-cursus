/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_and_exec_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:54:07 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:52:56 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handles the input redirection for a command before execution.
 *
 * Sets up standard input based on the command’s `input_fd`, previous pipe,
 * or `/dev/null`
 * if it's not the first command and no input is defined.
 *
 * @param shell the main shell structure.
 * @param i the index of the current command.
 * @param prev_pipe0 the read end of the previous pipe (if any).
 *
 * @return void.
 */
void	handle_cmd_input(t_shell *shell, int i, int prev_pipe0)
{
	int	dev_null;

	if (shell->cmd[i]->input_fd > 0)
	{
		dup2(shell->cmd[i]->input_fd, STDIN_FILENO);
		close(shell->cmd[i]->input_fd);
	}
	else if (prev_pipe0)
	{
		dup2(prev_pipe0, STDIN_FILENO);
		close(prev_pipe0);
	}
	else if (i != 0)
	{
		dev_null = open("/dev/null", O_RDONLY);
		if (dev_null == -1)
		{
			perror("Error opening /dev/null");
			exit(1);
		}
		dup2(dev_null, STDIN_FILENO);
		close(dev_null);
	}
}

/**
 * @brief Frees and closes resources in case of execution failure or exit.
 *
 * Handles memory cleanup and file descriptor closure when `execve` fails
 * or when a built-in command is executed in a forked process.
 *
 * @param path the resolved path to the executable (can be NULL).
 * @param envp the environment array (can be NULL).
 * @param prev_pipe0 the read end of the previous pipe (if any).
 *
 * @return void. This function calls `ms_exit` and does not return normally.
 */
static void	error_exec(char *path, char **envp, int prev_pipe0)
{
	t_shell	*shell;

	shell = get_shell();
	if (path)
		free(path);
	free_arr(envp);
	if (prev_pipe0)
		close(prev_pipe0);
	ms_exit(&shell, NULL);
}

/**
 * @brief Attempts to execute a command using `execve`.
 *
 * Resolves the command path using `create_path`,
 * then executes it with `execve`.
 * On failure,
 * prints an error message and performs cleanup through `error_exec`.
 *
 * @param args the command and its arguments.
 * @param envp the environment variables as an array.
 * @param prev_pipe0 the read end of the previous pipe (if any).
 *
 * @return (void. This function does not return normally); it exits on failure.
 */
static void	exec_command(char **args, char **envp, int prev_pipe0)
{
	char	*path;

	path = create_path(args[0], envp);
	if (!path)
	{
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		get_shell()->last_exit_code = 127;
	}
	else if (execve(path, args, envp) == -1)
		perror("execve error");
	error_exec(path, envp, prev_pipe0);
}

/**
 * @brief Closes all input and output redirection file descriptors.
 *
 * Iterates through all commands and closes any open input or output
 * file descriptors to prevent resource leaks.
 *
 * @return void.
 */
void	close_all_fd_red(void)
{
	t_shell	*shell;
	int		i;

	shell = get_shell();
	i = 0;
	while (shell->cmd[i])
	{
		if (shell->cmd[i]->input_fd > 0)
			close(shell->cmd[i]->input_fd);
		if (shell->cmd[i]->output_fd > 1)
			close(shell->cmd[i]->output_fd);
		i++;
	}
}

/**
 * @brief Handles the output redirection and executes the command.
 *
 * Redirects standard output if needed, executes built-in or external commands,
 * and ensures proper pipe and file descriptor cleanup. If `execve` fails or the
 * command is not found, handles the error and exits.
 *
 * @param shell the shell structure.
 * @param i the index of the current command.
 * @param prev_pipe0 the read end of the previous pipe (if any).
 *
 * @return void. This function may exit the process if execution fails.
 */
void	handle_cmd_output_and_execute(t_shell *shell, int i, int prev_pipe0)
{
	if (shell->cmd[i]->output_fd > 1)
	{
		dup2(shell->cmd[i]->output_fd, STDOUT_FILENO);
		close(shell->cmd[i]->output_fd);
	}
	else if (shell->cmd[i + 1])
		dup2(shell->cmd[i]->pipe_fds[1], STDOUT_FILENO);
	if (prev_pipe0)
		close(prev_pipe0);
	if (is_build_in(shell->cmd[i]))
		build_ins(shell->cmd[i]);
	if (shell->cmd[i + 1])
	{
		close(shell->cmd[i]->pipe_fds[0]);
		close(shell->cmd[i]->pipe_fds[1]);
	}
	if (!is_build_in(shell->cmd[i]))
		exec_command(shell->cmd[i]->arg, make_env_arr(shell->env), prev_pipe0);
	close_all_fd_red();
	error_exec(NULL, NULL, 0);
}
