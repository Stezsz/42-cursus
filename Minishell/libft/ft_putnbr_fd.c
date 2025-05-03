/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:05:06 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:55:26 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	j;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		j = (long)(n);
		j *= -1;
	}
	else
		j = (long)n;
	if (j <= 9)
		ft_putchar_fd(j + 48, fd);
	else
	{
		ft_putnbr_fd(j / 10, fd);
		ft_putnbr_fd(j % 10, fd);
	}
}
/* int main()
{
	ft_putnbr_fd(-2147483648, 1);
} */
