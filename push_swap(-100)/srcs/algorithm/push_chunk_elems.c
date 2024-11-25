/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:43:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/25 21:00:49 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_chunk_elems(t_stack *a, t_stack *b, int subdiv)
{
	int *elem;
	int index;
	int i;

	elem = get_chunk_elem(a, subdiv);
	while (elem)
	{
		i = 0;

		index = get_elem_index(*a, *elem);
		if (index == -1)
		{
			free(elem);
			return;
		}
		if (index <= a->size / 2)
		{
			while (i++ < index)
				ra_rotate_a(a, false);
		}
		else
		{
			while (i++ < a->size - index)
				rra_reverse_rotate_a(a, false);
		}
		pb_push_b(a, b);
		elem = get_chunk_elem(a, subdiv);
	}
}

