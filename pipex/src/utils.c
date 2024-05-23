/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:41:18 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:57 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_cmd(t_pipes **exec, char **envp, int index)
{
	char	**path;
	int		i;
	char	*str;

	i = 0;
	path = ft_split((*exec)[0].path_var, ':');
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		str = ft_strjoin(str, (*exec)[index].cmd);
		execute_command(*exec, envp, str, index);
		free(str);
		i++;
	}
	free(path);
}

int	last_cmd(t_pipes *exec)
{
	int	i;

	i = 0;
	while (exec[i].value != 1)
		i++;
	return (i);
}

void	alloc_mem(int ***pipe_fd, t_pipes **exec)
{
	int	i;
	int	cmd_nbr;

	i = 0;
	cmd_nbr = last_cmd(*exec);
	*pipe_fd = ft_calloc((cmd_nbr + 1), sizeof(int *));
	if (*pipe_fd == NULL)
		return ;
	while (i < (cmd_nbr + 1))
	{
		(*pipe_fd)[i] = ft_calloc(2, sizeof(int));
		if ((*pipe_fd)[i] == NULL)
		{
			ft_putstr_fd("Error allocating memory", 2);
			free_pipes(pipe_fd, i, exec);
			exit (1);
		}
		i++;
	}
}

void	waiting_for_children(t_pipes **exec, int **pipe_fd)
{
	int	i;
	int	status;
	int	exit_value;
	int	cmd_nbr;

	i = 0;
	cmd_nbr = last_cmd(*exec);
	exit_value = 0;
	while (!((*exec)[i].value))
	{
		wait(&status);
		if (WEXITSTATUS(status) == 127)
			exit_value = 1;
		if (status == -1)
		{
			perror("wait");
			free_pipes(&pipe_fd, cmd_nbr + 1, exec);
			exit(WEXITSTATUS(status));
		}
		i++;
	}
	free_pipes(&pipe_fd, cmd_nbr + 1, exec);
	if (exit_value == 1)
		exit (127);
	exit(WEXITSTATUS(status));
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = (char *)malloc((ft_strlen2(s1) + ft_strlen2(s2) + 2));
	if (!buffer)
		return (NULL);
	while (s1 && s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = ' ';
	i++;
	while (s2 && s2[j])
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}
