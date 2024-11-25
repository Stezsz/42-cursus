/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:27 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/21 17:11:27 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack *a, t_stack *b)
{
	int	i;
	int	index;

	while (!is_empty(b))
	{
		i = 0;
		index = get_elem_index(*b, get_max(b));
		if (index == -1)
			return ;
		if (index <= b->size / 2)
			while (i++ < index)
				rb_rotate_b(b, false);
		else
			while (i++ < b->size - index)
				rrb_reverse_rotate_b(b, false);
		pa_push_a(a, b);
	}
}
