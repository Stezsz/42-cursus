/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:54 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/16 13:58:54 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(t_stack a, int elem)
{
	int	index;

	index = 0;
	if (!a.top)
		return (-1);
	while (a.top && a.top->value != elem)
	{
		a.top = a.top->bellow;
		index++;
	}
	return (index);
}
