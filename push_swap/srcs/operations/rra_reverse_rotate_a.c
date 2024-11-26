/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_reverse_rotate_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:15:52 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/17 13:15:52 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra: reverse rotate a - shift down all elements of stack a b 1.
 * the last element becomes the first one. */
void	rra_reverse_rotate_a(t_stack *a, int flag)
{
	push_elem(a, new_elem(a->bottom->value));
	poop_elem(a);
	if (!flag)
		ft_putstr("rra\n");
}
