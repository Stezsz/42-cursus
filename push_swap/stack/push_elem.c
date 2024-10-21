/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:13:01 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/15 17:13:01 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem(t_stack *stack, t_node *elem)
{
	if (!is_empty(stack))
	{
		elem->bellow = stack->top;
		stack->top->above = elem;
	}
	else
		stack->bottom = elem;
	stack->top = elem;
	stack->size++;
}
