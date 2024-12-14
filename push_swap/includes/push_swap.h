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
void	chunks_sort(t_stack *a, t_stack *b);
void	generic_sort(t_stack *a, t_stack *b);
int		get_chunk_elem(t_stack *a, int subdiv);
int		get_elem_index(t_stack a, int elem);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
void	move_to_top_b(t_stack *b, int index);
void	push_chunk_elems(t_stack *a, t_stack *b, int subdiv);
void	push_to_stack_a(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);

/* ------ Checks Functions ------ */
void	get_input(t_stack *a, t_stack *b, char **av, int size);
int		is_duplicates(char **av, int size);
int		is_empty(t_stack *stack);
int		is_greater_than_int(char **av, int size);
int		is_integer(char **av, int size);
int		is_sorted(t_stack stack);
void	put_error(char *msg);

/* ---- Operations Functions ---- */
void	pa_push_a(t_stack *a, t_stack *b);
void	pb_push_b(t_stack *a, t_stack *b);
void	ra_rotate_a(t_stack *a, int flag);
void	rb_rotate_b(t_stack *b, int flag);
void	rr_ra_rb(t_stack *a, t_stack *b);
void	rra_reverse_rotate_a(t_stack *a, int flag);
void	rrb_reverse_rotate_b(t_stack *b, int flag);
void	rrr_rra_rrb(t_stack *a, t_stack *b);
void	sa_swap_a(t_stack *a, int flag);
void	sb_swap_b(t_stack *b, int flag);
void	ss_sa_sb(t_stack *a, t_stack *b);

/* ------ Stack Functions ------- */
void	free_stack(t_stack *stack);
t_stack	*init_stack(void);
t_node	*new_elem(int data);
void	poop_elem(t_stack *a);
void	pop_elem(t_stack *stack);
void	push_elem_bottom(t_stack *stack, t_node *elem);
void	push_elem(t_stack *stack, t_node *elem);

/* ------- Utils Functions ------ */
long	ft_atoi(const char *str);
void	ft_putstr(char *str);
char	**ft_split(const char *s, char c);
void	free_split(char **split);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(int *a, int *b);

#endif
