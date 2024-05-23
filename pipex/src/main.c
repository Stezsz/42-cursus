/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:23:14 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:40 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipes	*exec;
	int		args;

	exec = NULL;
	args = argc - 3;
	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc") && argc < 6))
		not_enough_args(argc, argv);
	if (!ft_strcmp(argv[1], "here_doc"))
		args = argc - 4;
	setup_pipes(args, argv, &exec, envp);
	pipex(&exec, argc, argv, envp);
	free(exec);
	return (0);
}
