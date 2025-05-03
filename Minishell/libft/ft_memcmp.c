/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:05:40 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:54:57 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s3;
	const unsigned char	*s4;
	size_t				i;

	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (s3[i] == s4[i] && i < (n -1))
		i++;
	return ((s3[i] - s4[i]));
}
