/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:37:53 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:01:34 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	first_children(t_pipes **exec, char **envp, int **pipe_fd)
{
	int	cmd_nbr;

	cmd_nbr = last_cmd(*exec);
	(*exec)[0].pid = fork();
	if ((*exec)[0].pid == -1)
		perror("fork");
	else if ((*exec)[0].pid == 0)
	{
		dup2((*exec)[0].fd, STDIN_FILENO);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
		close_pipes(pipe_fd, *exec);
		check_cmd(exec, envp, 0);
		if (errno == ENOENT || ft_strcmp((*exec)[0].cmd, "") == 0)
		{
			ft_putstr_fd((*exec)[0].cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_pipes(&pipe_fd, cmd_nbr + 1, exec);
			exit (0);
		}
		free_pipes(&pipe_fd, cmd_nbr + 1, exec);
		perror("Commmand");
		exit (1);
	}
}

void	children_processes(t_pipes **exec, char **envp, int **pipe_fd, int i)
{
	int	cmd_nbr;

	cmd_nbr = last_cmd(*exec);
	(*exec)[i].pid = fork();
	if ((*exec)[i].pid == -1)
		perror("fork");
	else if ((*exec)[i].pid == 0)
	{
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(pipe_fd[i][1], STDOUT_FILENO);
		close_pipes(pipe_fd, *exec);
		check_cmd(exec, envp, i);
		if (errno == ENOENT || ft_strcmp((*exec)[i].cmd, "") == 0)
		{
			ft_putstr_fd((*exec)[i].cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_pipes(&pipe_fd, cmd_nbr + 1, exec);
			exit (0);
		}
		free_pipes(&pipe_fd, cmd_nbr + 1, exec);
		perror("Commmand");
		exit (1);
	}
}

static void	parent_process(t_pipes **exec, char **envp, int **pipe_fd, int i)
{
	int	cmd_nbr;

	cmd_nbr = last_cmd(*exec);
	(*exec)[i].pid = fork();
	if ((*exec)[i].pid == -1)
		perror("fork");
	else if ((*exec)[i].pid == 0)
	{
		dup2((*exec)[1].fd, STDOUT_FILENO);
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
		close_pipes(pipe_fd, *exec);
		check_cmd(exec, envp, i);
		if (errno == ENOENT || ft_strcmp((*exec)[i].cmd, "") == 0)
		{
			ft_putstr_fd((*exec)[i].cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_pipes(&pipe_fd, cmd_nbr + 1, exec);
			exit (127);
		}
		free_pipes(&pipe_fd, cmd_nbr + 1, exec);
		perror("Commmand");
		exit (1);
	}
}

void	execute_pipes(t_pipes **exec, int ac, char **envp, char **av)
{
	int		**pipe_fd;
	int		i;

	i = 1;
	pipe_fd = NULL;
	if (ft_strcmp(av[1], "here_doc") == 0)
		ac = ac - 4;
	else
		ac = ac - 3;
	alloc_mem(&pipe_fd, exec);
	if (open_pipes(ac, pipe_fd) == -1)
		return ;
	first_children(exec, envp, pipe_fd);
	while (i < (ac - 1))
	{
		children_processes(exec, envp, pipe_fd, i);
		i++;
	}
	parent_process(exec, envp, pipe_fd, i);
	close_pipes(pipe_fd, *exec);
	waiting_for_children(exec, pipe_fd);
}

void	execute_command(t_pipes *exec, char **envp, char *cmd, int index)
{
	char	**flags;
	char	*buffer;
	int		i;
	int		flag;

	i = 0;
	buffer = NULL;
	flag = ft_strcmp(exec[index].cmd, "");
	if (flag == 0)
		buffer = "error";
	else
		buffer = ft_strjoin2(exec[index].cmd, exec[index].flags);
	flags = ft_split(buffer, ' ');
	execve(cmd, flags, envp);
	if (flag)
		free(buffer);
	while (flags[i])
	{
		free(flags[i]);
		i++;
	}
	free(flags);
}
