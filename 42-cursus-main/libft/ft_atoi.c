/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:39:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/28 14:39:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int				 main(void)
{
		printf("%d\n",ft_atoi("0"));
		printf("%d\n",ft_atoi("546:5"));
		printf("%d\n",ft_atoi("-4886"));
		printf("%d\n",ft_atoi("+548"));
		printf("%d\n",ft_atoi("054854"));
		printf("%d\n",ft_atoi("000074"));
		printf("%d\n",ft_atoi("+-54"));
		printf("%d\n",ft_atoi("-+48"));
		printf("%d\n",ft_atoi("--47"));
		printf("%d\n",ft_atoi("++47"));
		printf("%d\n",ft_atoi("+47+5"));
		printf("%d\n",ft_atoi("-47-5"));
		printf("%d\n",ft_atoi("\e475"));
		printf("%d\n",ft_atoi("\t\n\r\v\f  469 \n"));
		printf("%d\n",ft_atoi("-2147483648"));
		printf("%d\n",ft_atoi("2147483647"));
		printf("%d\n",ft_atoi("\t\n\r\v\fd469 \n"));
		printf("%d\n",ft_atoi("\n\n\n  -46\b9 \n5d6"));
		printf("%d\n",ft_atoi(""));
}*/
