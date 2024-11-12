/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:25:42 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/15 18:25:42 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted: a function to check if stack is sorted or not */
int	is_sorted(t_stack stack)
{
	if (is_empty(&stack))
		return (1);
	while (stack.top->bellow)
	{
		if (stack.top->value > stack.top->bellow->value)
			return (0);
		stack.top = stack.top->bellow;
	}
	return (1);
}
