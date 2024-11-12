/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:23:48 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/18 12:23:48 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa: push a - take the first element at the top of b and put it at top of a.
 * (do nothing if b is empty). */

void	pa_push_a(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	push_elem(a, new_elem(b->top->value));
	pop_elem(b);
	ft_putstr("pa\n");
}
