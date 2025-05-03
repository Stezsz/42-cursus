/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:11:06 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:56:24 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + (int)(ft_strlen(s))));
	while (l >= 0)
	{
		if (s[l] == (unsigned char)c)
			return ((char *)s + l);
		l--;
	}
	return (0);
}
