/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:42:33 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/25 20:42:35 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_tokens(void)
// {
// 	t_shell	*shell = get_shell();
// 	t_token	*token;
// 	token = shell->tokens;
// 	if (!token)
// 		return;
// 	printf("TOKENS NEXT: ");
// 	while(token)
// 	{
// 		printf("%p -> ",token);
// 		token = token->next;
// 	}
// 	printf("\n");
// 	token = tokenlast(shell->tokens);
// 	printf("TOKENS PREV: ");
// 	while(token)
// 	{
// 		printf("<- %p" ,token);
// 		token = token->prev;
// 	}
// 	token = shell->tokens;
// 	printf("\n");
// 	printf("STR : ");
// 	while(token)
// 	{
// 		printf("%s ",token->str);
// 		token = token->next;
// 	}
// 		token = shell->tokens;
// 	printf("\n");
// 	printf("TYPE : ");
// 	while(token)
// 	{
// 		printf("%u ",token->type);
// 		token = token->next;
// 	}
// 	printf("\n");
// }
// void print_cmd_array(void)
// {
// 	t_shell	*shell;
// 	int	k;
// 	int	i;

// 	shell = get_shell();
// 	k = 0;
// 	while (shell->cmd[k])
// 	{
// 	printf("Command %d\n", k);
// 	i = 0;
// 	while (shell->cmd[k]->arg[i])
// 	{
// 		printf("arg %d: %s\n", i, shell->cmd[k]->arg[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (shell->cmd[k]->red && shell->cmd[k]->red[i])
// 	{
// 		printf("red %d: %s\n", shell->cmd[k]->red[i]->type,
// shell->cmd[k]->red[i]->str);
// 		i++;
// 	}
// 	k++;
// 	}
// }
