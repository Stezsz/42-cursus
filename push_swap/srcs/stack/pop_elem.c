/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:10 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/15 18:30:10 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_elem(t_stack *stack)
{
	t_node	*tmp;

	if (!is_empty(stack))
	{
		tmp = stack->top;
		stack->top = stack->top->bellow;
		if (stack->size == 1)
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
		else
			stack->top->above = NULL;
		stack->size--;
		free(tmp);
	}
}
