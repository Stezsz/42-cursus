/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:14:44 by strodrig          #+#    #+#             */
/*   Updated: 2024/10/14 18:14:44 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

/* -------- Nós da pilha -------- */
typedef struct s_node
{
	int				value;
	struct s_node	*above;
	struct s_node	*bellow;
}	t_node;

/* ----- Estrutura da pilha ----- */
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* ----- Algorithm Functions ---- */
void	basic_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	chunks_sort(t_stack *a, t_stack *b);
void	push_to_stack_a(t_stack *a, t_stack *b);
void	push_chunck_elems(t_stack *a, t_stack *b, int subdiv);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_elem_index(t_stack a, int elem);
int		*get_chunck_elem(t_stack *a, int subdiv);

/* ------ Checks Functions ------ */
void	get_input(t_stack *a, t_stack *b, char **av, int size);
void	put_error(char *msg);
int		is_integer(char **av, int size);
int		is_greater_than_int(char **av, int size);
int		is_duplicates(char **av, int size);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack stack);

/* ---- Operations Functions ---- */
void	ra_rotate_a(t_stack *a, int flag);
void	sa_swap_a(t_stack *a, int flag);
void	rra_reverse_rotate_a(t_stack *a, int flag);
void	pb_push_b(t_stack *a, t_stack *b);
void	pa_push_a(t_stack *a, t_stack *b);
void	rrb_reverse_rotate_b(t_stack *b, int flag);
void	rb_rotate_b(t_stack *b, int flag);

/* ------ Stack Functions ------- */
t_stack	*init_stack(void);
t_node	*new_elem(int data);
void	push_elem(t_stack *stack, t_node *elem);
void	free_stack(t_stack *stack);
void	pop_elem(t_stack *stack);
void	poop_elem(t_stack *a);
void	push_elem_bottom(t_stack *stack, t_node *elem);

/* ------- Utils Functions ------ */
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif
