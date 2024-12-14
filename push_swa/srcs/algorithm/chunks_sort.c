/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:55 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 17:00:16 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stack *a, int index)
{
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
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, int low, int high)
{
	t_node	*curr;
	int		index;

	curr = a->top;
	while (curr)
	{
		if (curr->value >= low && curr->value < high)
		{
			index = get_elem_index(*a, curr->value);
			move_to_top(a, index);
			pb_push_b(a, b);
		}
		curr = curr->bellow;
	}
}

static int	define_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	else if (size <= 500)
		return (40);
	return (50);
}

void	chunks_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	low;
	int	high;

	chunk_size = define_chunk_size(a->size);
	low = get_min(a);
	high = low + chunk_size;
	while (!is_empty(a))
	{
		push_chunk_to_b(a, b, low, high);
		low += chunk_size;
		high += chunk_size;
	}
	push_to_stack_a(a, b);
}
