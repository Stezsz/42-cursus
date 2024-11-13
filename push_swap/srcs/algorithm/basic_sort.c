/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:57 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/16 13:44:57 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_sort(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	while (!is_sorted(*a))
	{
		i = 0;
		index = get_elem_index(*a, get_min(a));
		if (index == -1)
			return ;
		if (index <= a->size / 2)
			while (i++ < index)
				ra_rotate_a(a, false);
		else
			while (i++ < a->size - index)
				rra_reverse_rotate_a(a, false);
		if (!is_sorted(*a))
			pb_push_b(a, b);
	}
	while (!is_empty(b))
		pa_push_a(a, b);
}
