/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:54:02 by strodrig          #+#    #+#             */
/*   Updated: 2024/09/16 12:54:02 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%sserver: unexpected error.\n");
	exit(EXIT_FAILURE);
}

void	send_bit(pid_t server_pid, char c, int bit)
{
	if (bit < 8)
	{
		if (c & (1 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		send_bit(server_pid, c, bit +1);
	}
}

void	send_char(pid_t server_pid, char c)
{
	send_bit(server_pid, c, 0);
}

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid server PID.\n");
		return (1);
	}
	send_string(server_pid, av[2]);
	return (0);
}
