/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:07:30 by strodrig          #+#    #+#             */
/*   Updated: 2024/03/01 21:07:30 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char *s1;

	i = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * i);
	if (!(s1))
		return (NULL);
	ft_strcpy(s1, s);
	return (s1);
}
/*
#include<stdio.h>
int main()
{
	char source[] = "Banana";

	printf("%s", ft_strdup(source));
}
*/
