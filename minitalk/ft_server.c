/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:54:09 by strodrig          #+#    #+#             */
/*   Updated: 2024/09/16 12:54:09 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%s\nserver: unexpected error.");
	exit(EXIT_FAILURE);
}

void	handle_signal(int signal)
{
	static int	current_char = 0;
	static int	bit_count = 0;

	if (signal == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\n\t\tPID: %d\t\t\tBy: strodrig\n", getpid());
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		signal_error();
	}
	while (1)
		pause();
	return (0);
}
