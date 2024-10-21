/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:55 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/16 13:44:55 by strodrig         ###   ########.fr       */
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
		div = 6;
	else
		div = 12;
	min = get_min(a);
	max = get_max(a);
	subdiv = (min + max) / div;
	while (!is_empty(a))
		push_chunck_elems(a, b, subdiv * i++);
	push_to_stack_a(a, b);
}
