/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:34:16 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/12 14:34:16 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sb: swap b - swap the first 2 elements at the top of stack b.
 * (do nothing if there is only one of no elements). */
void	sb_swap_b(t_stack *b, int flag)
{
	int	tmp;

	if (is_empty(b))
		return ;
	tmp = b->top->value;
	b->top->value = b->top->bellow->value;
	b->top->bellow->value = tmp;
	if (!flag)
		ft_putstr("sb\n");
}
