/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:57 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 12:52:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_sort(t_stack *a, t_stack *b)
{
	int	index;

	while (a->size > 3)
	{
		index = get_elem_index(*a, get_min(a));
		if (index <= a->size / 2)
			while (index-- > 0)
				ra_rotate_a(a, false);
		else
			while (index++ < a->size)
				rra_reverse_rotate_a(a, false);
		pb_push_b(a, b);
	}
	sort_three(a);
	while (!is_empty(b))
		pa_push_a(a, b);
}
