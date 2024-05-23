/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:52:29 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:01:19 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	not_enough_args(int ac, char **av)
{
	if (av[1] && ft_strcmp(av[1], "here_doc") == 0 && ac < 6)
		write(2, "Not enough arguments with here_docs\n", 36);
	else
		write(2, "Not enough arguments\n", 21);
	exit (1);
}

void	error_waiting_children(t_pipes **exec)
{
	close((*exec)[0].fd);
	close((*exec)[1].fd);
	free(*exec);
}
