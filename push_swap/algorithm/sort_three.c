/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:58 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/16 13:44:58 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	min;

	min = get_elem_index(*a, get_min(a));
	if (min == 1)
	{
		if (a->top->value > a->bottom->value)
			ra_rotate_a(a, false);
		else
			sa_swap_a(a, false);
	}
	else if (min == 2)
	{
		if (a->top->value > a->top->bellow->value)
		{
			sa_swap_a(a, false);
			rra_reverse_rotate_a(a, false);
		}
		else
			rra_reverse_rotate_a(a, false);
	}
	else
	{
		sa_swap_a(a, false);
		ra_rotate_a(a, false);
	}
}
