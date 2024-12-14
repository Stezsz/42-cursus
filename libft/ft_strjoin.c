/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:07:26 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/02 18:07:26 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && s1[++len] != '\0')
		str[++i] = s1[len];
	len = -1;
	while (s2 != NULL && s2[++len] != '\0')
		str[++i] = s2[len];
	str[++i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_strjoin("teste", "banana");
	printf("%s\n", result);
	return (0);
}*/
