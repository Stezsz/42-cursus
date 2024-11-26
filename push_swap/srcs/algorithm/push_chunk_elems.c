/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:43:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 13:45:18 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_elems(t_stack *a, t_stack *b, int subdiv)
{
	int	elem;
	int	index;

	elem = get_chunk_elem(a, subdiv);
	while (elem != -1)
	{
		elem = get_chunk_elem(a, subdiv);
		index = get_elem_index(*a, elem);
		if (index <= a->size / 2)
		{
			while (index-- > 0)
				ra_rotate_a(a, false);
		}
		else
		{
			while (index++ < a->size)
				rra_reverse_rotate_a(a, false);
		}
		pb_push_b(a, b);
	}
}
