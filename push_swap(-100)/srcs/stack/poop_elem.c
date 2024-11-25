/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poop_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:20:21 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/17 13:20:21 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	poop_elem(t_stack *stack)
{
	t_node	*tmp;

	if (!is_empty(stack))
	{
		tmp = stack->bottom;
		stack->bottom = stack->bottom->above;
		if (stack->size == 1)
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
		else
			stack->bottom->bellow = NULL;
		stack->size--;
		free(tmp);
	}
}
