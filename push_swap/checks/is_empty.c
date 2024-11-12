/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:06:03 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/15 18:06:03 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* a funciton to check if stack empty or not */
int	is_empty(t_stack *stack)
{
	return (stack->top == NULL && stack->bottom == NULL);
}
