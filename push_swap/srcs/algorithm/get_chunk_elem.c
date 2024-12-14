/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:44:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 13:34:17 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_elem(t_stack *a, int subdiv)
{
	t_node	*top;
	t_node	*bottom;

	if (!a || a->size == 0)
		return (EXIT_FAILURE);
	top = a->top;
	bottom = a->bottom;
	while (top && bottom && top != bottom->bellow)
	{
		if (top->value <= subdiv)
			return (top->value);
		if (bottom->value <= subdiv)
			return (bottom->value);
		top = top->bellow;
		bottom = bottom->above;
	}
	return (EXIT_FAILURE);
}
