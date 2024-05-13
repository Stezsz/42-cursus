/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:44:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/06 13:44:20 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

/*void uppercase(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = toupper(*c);
	else
		*c = tolower(*c);
}

int main(void)
{
	char str[] = "Hello, World!";

	ft_striteri(str, uppercase);
	printf("%s\n", str);

	return 0;
}*/
