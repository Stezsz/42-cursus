/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:57:15 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:52:31 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_sigint_handler(int signum)
{
	t_shell	*shell;

	shell = get_shell();
	(void)signum;
	write(1, "\n", 1);
	close(shell->heredoc_pipe[1]);
	close_all_fd_red();
	shell->last_exit_code = 130;
	ms_exit(&shell, NULL);
}

void	here_sigint(void)
{
	struct sigaction	sa;
	t_shell				*shell;

	shell = get_shell();
	sa.sa_handler = here_sigint_handler;
	sa.sa_flags = SA_RESTART;
	if (sigemptyset(&sa.sa_mask) || sigaction(SIGINT, &sa, NULL))
	{
		write(2, "sigaction failed at interactive mode in SIGINT\n", 48);
		ms_exit(&shell, NULL);
	}
}
