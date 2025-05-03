/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:53:03 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:52:24 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_handler(int signal)
{
	t_shell	*shell;

	shell = get_shell();
	if (signal == SIGQUIT)
		shell->last_exit_code = 131;
	if (signal == SIGINT)
		shell->last_exit_code = 130;
}

void	exec_mode(void)
{
	struct sigaction	sa;

	sa.sa_handler = exec_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL))
	{
		perror("sigaction failed at execution mode in SIGINT");
		exit(1);
	}
	if (sigaction(SIGQUIT, &sa, NULL))
	{
		perror("sigaction failed at execution mode in SIGQUIT");
		exit(1);
	}
}
