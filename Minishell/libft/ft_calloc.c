/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:06:59 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:53:26 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	max;

	max = nmemb * size;
	if (nmemb && size && max / size != nmemb)
		return (NULL);
	array = malloc(max);
	if (!array)
		return (NULL);
	ft_bzero(array, max);
	return (array);
}
