/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:22:09 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/18 12:22:09 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pb: push b - take the first element of top of a and put it at the top of b.
 * (do nothing if a emepty). */
void	pb_push_b(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	push_elem(b, new_elem(a->top->value));
	pop_elem(a);
	ft_putstr("pb\n");
}
