/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_att.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:35:34 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/25 21:01:35 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief frees a cmd->redir memory and sets all regarding
 * pointers to NULL.
 *
 *auxiliar functions: free.
 * @param cmd adress of pointer to t_cmd allocated struct.
 * @return void.
 */
void	free_cmd_redir(t_cmd **cmd)
{
	int	i;

	i = 0;
	while ((*cmd)->redirections && (*cmd)->redirections[i])
	{
		(*cmd)->redirections[i]->str = NULL;
		free ((*cmd)->redirections[i]);
		(*cmd)->redirections[i++] = NULL;
	}
	if ((*cmd)->redirections)
		free ((*cmd)->redirections);
	(*cmd)->redirections = NULL;
	i = 0;
	while ((*cmd)->heredocs && (*cmd)->heredocs[i])
	{
		(*cmd)->heredocs[i]->str = NULL;
		free ((*cmd)->heredocs[i]);
		(*cmd)->heredocs[i++] = NULL;
	}
	if ((*cmd)->heredocs)
		free ((*cmd)->heredocs);
	(*cmd)->heredocs = NULL;
}

/**
 * @brief frees shell->cmd memory and sets all regarding
 * pointers to NULL.
 *
 *auxiliar functions: get_shell, free.
 * @return void.
 */
void	free_cmds(void)
{
	int	k;

	k = 0;
	while (get_shell() && get_shell()->cmd \
			&& get_shell()->cmd[k])
	{
		if (get_shell()->cmd[k]->arg)
			free (get_shell()->cmd[k]->arg);
		get_shell()->cmd[k]->arg = NULL;
		free_cmd_redir(&(get_shell()->cmd[k]));
		free(get_shell()->cmd[k]);
		get_shell()->cmd[k++] = NULL;
	}
	if (get_shell() && get_shell()->cmd)
		free (get_shell()->cmd);
	get_shell()->cmd = NULL;
}

/**
 * @brief frees shell->tokens memory and sets all regarding
 * pointers to NULL.
 *
 *auxiliar functions: get_shell, free.
 * @return void.
 */
void	free_tokens(void)
{
	t_shell	*shell;
	t_token	*next;

	shell = get_shell();
	while (shell->tokens)
	{
		next = shell->tokens->next;
		if (shell->tokens->str)
		{
			free(shell->tokens->str);
			shell->tokens->str = NULL;
		}
		free(shell->tokens);
		shell->tokens = NULL;
		shell->tokens = next;
	}
	shell->tokens = NULL;
}

/**
 * @brief frees shell->cmd and shell->tokens memory and sets all regarding
 * pointers to NULL.
 *
 *auxiliar functions: free_tokens, free_cmds.
 * @return void.
 */
void	free_atributes(void)
{
	free_tokens();
	free_cmds();
}
