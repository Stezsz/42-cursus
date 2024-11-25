/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:55 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/25 20:56:48 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sort(t_stack *a, t_stack *b)
{
	int	subdiv;
	int	div;
	int	min;
	int	max;
	int	i;

	i = 1;
	if (a->size >= 100 && a->size < 500)
		div = a->size / 20;
	else
		div = a->size / 50;
	if (div < 1)
		div = 1;
	min = get_min(a);
	max = get_max(a);
	subdiv = (max - min) / div;
	while (!is_empty(a))
		push_chunk_elems(a, b, subdiv * i++);
	push_to_stack_a(a, b);
}
