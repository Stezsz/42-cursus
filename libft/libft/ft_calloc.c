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

void	ft_count(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void *ft_calloc(size_t items, size_t size)
{
	char	*memory;

	memory = malloc(items * size);
	if(!(memory))
		return (NULL);
	ft_count(memory, (items * size));
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


