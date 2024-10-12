/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:26:53 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/06 13:26:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*char uppercase(char c, unsigned int i)
{
	if (i % 2 == 0)
		return toupper(c);
	else
		return tolower(c);
}

int	main(void)
{
	char	*res;

	res = ft_strmapi("Hello, World!", uppercase);
	printf("%s\n", res);
}*/
