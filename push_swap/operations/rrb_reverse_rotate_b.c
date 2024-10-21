/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_reverse_rotate_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:14:53 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/21 17:14:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rrb: reverse rotate b - shift down all elements of stack b by 1.
 * the last one becomes the first one. */
void	rrb_reverse_rotate_b(t_stack *b, int flag)
{
	push_elem(b, new_elem(b->bottom->value));
	poop_elem(b);
	if (!flag)
		ft_putstr("rrb\n");
}
