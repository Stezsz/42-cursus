/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:13:35 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/07 12:50:36 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_input(char **av, int *size)
{
	char	**split_args;
	int		i;

	split_args = NULL;
	i = 0;
	if (*size == 1)
	{
		split_args = ft_split(av[0], ' ');
		while (split_args[i])
			i++;
		*size = i;
	}
	return (split_args);
}

void	get_input(t_stack *a, t_stack *b, char **av, int size)
{
	char	**split_args;

	split_args = parse_input(av, &size);
	if (split_args)
		av = split_args;
	if (!is_integer(av, size) || is_greater_than_int(av, size)
		|| is_duplicates(av, size))
		put_error("Error\n");
	while (size)
		push_elem(a, new_elem(ft_atoi(av[--size])));
	if (is_sorted(*a))
	{
		free_stack(a);
		free(b);
		if (split_args)
			free_split(split_args);
		exit(EXIT_SUCCESS);
	}
	if (split_args)
		free_split(split_args);
}
