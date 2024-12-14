/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:54 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 13:25:02 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(t_stack a, int elem)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = a.top;
	while (tmp)
	{
		if (tmp->value == elem)
			return (index);
		tmp = tmp->bellow;
		index++;
	}
	return (-1);
}
