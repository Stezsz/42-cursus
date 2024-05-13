/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:39:12 by strodrig          #+#    #+#             */
/*   Updated: 2024/03/01 21:39:12 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*memory;

	if (items && size && items > (UINT_MAX / size))
		return (NULL);
	memory = (void *)malloc(items * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, (items * size));
	return (memory);
}

/*int	main(void)
{
	int *test;

	test = (void *)ft_calloc(40, sizeof(size_t));
	if (test != NULL)
		printf("Allocated\n");
	else
		printf("Can`t allocated");
}*/
