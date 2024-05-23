/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:27:02 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:01:11 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_pipes(int **pipe_fd, t_pipes *exec)
{
	int	i;
	int	cmd_nbr;

	i = 0;
	cmd_nbr = last_cmd(exec);
	while (i < cmd_nbr)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}

void	free_pipes(int ***pipe_fd, int index, t_pipes **exec)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free((*pipe_fd)[i]);
		i++;
	}
	free (*pipe_fd);
	close((*exec)[0].fd);
	close((*exec)[1].fd);
	free (*exec);
}

int	open_pipes(int num_pipes, int **pipe_fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (num_pipes))
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			perror("pipe");
			while (j < i)
			{
				close(pipe_fd[j][0]);
				close(pipe_fd[j][1]);
				j++;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}
