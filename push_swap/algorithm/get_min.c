/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:51:15 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:15 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	t_node		*tmp;
	int			min;

	tmp = stack->top;
	min = tmp->value;
	while (tmp->bellow)
	{
		tmp = tmp->bellow;
		if (min > tmp->value)
			min = tmp->value;
	}
	return (min);
}
