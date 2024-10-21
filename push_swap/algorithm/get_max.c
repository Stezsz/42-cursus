/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:30:38 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/21 16:30:38 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack->top;
	max = tmp->value;
	while (tmp->bellow)
	{
		tmp = tmp->bellow;
		if (max < tmp->value)
			max = tmp->value;
	}
	return (max);
}
