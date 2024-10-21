/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunck_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:44:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/21 16:44:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_chunck_elem(t_stack *a, int subdiv)
{
	t_node	*top;
	t_node	*bottom;
	int		i;
	int		j;

	top = a->top;
	bottom = a->bottom;
	i = 0;
	j = a->size - 1;
	while (i++ <= j--)
	{
		if (top->value <= subdiv)
			return (&top->value);
		else if (bottom->value <= subdiv)
			return (&bottom->value);
		top = top->bellow;
		bottom = bottom->above;
	}
	return (NULL);
}
