/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:27 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 16:59:22 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack *a, t_stack *b)
{
	int	max;
	int	index;

	while (!is_empty(b))
	{
		max = get_max(b);
		index = get_elem_index(*b, max);
		move_to_top_b(b, index);
		pa_push_a(a, b);
	}
}

void	move_to_top_b(t_stack *b, int index)
{
	if (index <= b->size / 2)
	{
		while (index-- > 0)
			rb_rotate_b(b, false);
	}
	else
	{
		while (index++ < b->size)
			rrb_reverse_rotate_b(b, false);
	}
}
