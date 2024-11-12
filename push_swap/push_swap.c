/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:12:53 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/14 18:12:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		exit (EXIT_FAILURE);
	a = init_stack();
	b = init_stack();
	get_input(a, b, av + 1, ac - 1);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		basic_sort(a, b);
	else
		chunks_sort(a, b);
	free_stack(a);
	free_stack(b);
	exit (EXIT_SUCCESS);
}
