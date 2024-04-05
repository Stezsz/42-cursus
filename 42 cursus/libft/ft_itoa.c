/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:44:30 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:30 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *new, unsigned int number, long int len)
{
	while (number > 0)
	{
		new[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (new);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*new;
	long int			len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = ft_len(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new))
		return (NULL);
	new[len--] = '\0';
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		new[0] = '-';
	}
	else
		number = n;
	new = ft_char(new, number, len);
	return (new);
}

#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(12345));
	//printf("%s\n", ft_itoa(2147483647));
	//printf("%s\n", ft_itoa(054));
	//printf("%s\n", ft_itoa(-456));
	//printf("%s\n", ft_itoa(-2147483647));
}
