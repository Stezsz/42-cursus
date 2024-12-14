/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:44:58 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/26 13:38:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->bellow->value
		&& a->top->value > a->bottom->value)
		ra_rotate_a(a, false);
	if (a->top->bellow->value > a->bottom->value)
		rra_reverse_rotate_a(a, false);
	if (a->top->value > a->top->bellow->value)
		sa_swap_a(a, false);
}
