/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:04:05 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/17 13:04:05 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa: swap a - swap the first 2 elements at the top of stack a.
 * (do nothing if there is only one or no elements). */
void	sa_swap_a(t_stack *a, int flag)
{
	int	tmp;

	if (is_empty(a))
		return ;
	tmp = a->top->value;
	a->top->value = a->top->bellow->value;
	a->top->bellow->value = tmp;
	if (!flag)
		ft_putstr("sa\n");
}
