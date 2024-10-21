/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:33 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/21 17:15:33 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rb: rotate b - shift all elements of stack b by 1.
 * the first element becomes the last one. */
void	rb_rotate_b(t_stack *b, int flag)
{
	push_elem_bottom(b, new_elem(b->top->value));
	pop_elem(b);
	if (!flag)
		ft_putstr("rb\n");
}
