/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:45 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/12 14:28:45 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rrr: reverse rotate a and reverse rotate b at the same time */
void	rrr_rra_rrb(t_stack *a, t_stack *b)
{
	rra_reverse_rotate_a(a, true);
	rrb_reverse_rotate_b(b, true);
	ft_putstr("rrr\n");
}
