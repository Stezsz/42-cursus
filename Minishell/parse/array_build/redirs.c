/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:37:17 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/25 22:36:20 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Assigns redirection types and values to a redirection array.
 *
 * Iterates through the token list up to a `PIPE` token,
 * identifying `REDIR` tokens and assigning their corresponding type
 * and string value to the `t_redir` array.
 * It determines the specific redirection type (`HERE_DOC`,
 * `APPEND`, `OUTFILE`, or `INFILE`)
 * based on the token string.
 *
 * @param token The token list to process.
 * @param redir A pointer to an array of `t_redir` structures to be filled.
 *
 * @return void.
 *
 * Auxiliary functions: ft_strncmp.
 */
void	assign_redirs(t_token *token, t_redir ***redir)
{
	int	i;

	i = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == REDIR)
		{
			(*redir)[i]->type = token->next->type;
			(*redir)[i]->str = token->next->str;
			if (ft_strncmp(token->str, "<<", 2) == 0)
				(*redir)[i++]->type = HERE_DOC;
			else if (!ft_strncmp(token->str, ">>", 2))
				(*redir)[i++]->type = APPEND;
			else if (!ft_strncmp(token->str, ">", 2))
				(*redir)[i++]->type = OUTFILE;
			else
				(*redir)[i++]->type = INFILE;
		}
		token = token->next;
	}
	(*redir)[i] = NULL;
}

/**
 * @brief Extracts and initializes redirection structures from a token list.
 *
 * Counts the number of redirections (`REDIR` tokens) in the given token list
 * and allocates memory for an array of `t_redir` structures.
 * Then, it initializes
 * each redirection structure and assigns them using `assign_redirs`.
 *
 * If memory allocation fails, the function returns `NULL`.
 *
 * @param token The token list to process.
 *
 * @return A pointer to an array of `t_redir` structures, or `NULL` on failure.
 *
 * Auxiliary functions: ft_calloc, assign_redirs.
 */
t_redir	**get_red(t_token *token)
{
	int		redir_num;
	int		i;
	t_token	*tmp;
	t_redir	**red;

	redir_num = 0;
	tmp = token;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == REDIR)
			redir_num++;
		tmp = tmp->next;
	}
	red = ft_calloc(sizeof(t_redir *), redir_num + 1);
	if (!red)
		return (NULL);
	i = 0;
	while (i < redir_num)
	{
		(red)[i] = ft_calloc(sizeof(t_redir), 1);
		if (!(red)[i++])
			return (NULL);
	}
	assign_redirs(token, &red);
	return (red);
}
