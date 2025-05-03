/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:37:01 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/25 21:09:43 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief exits with exit status 0 if executable was ran with argumments.
 * @param ac number of arguments passed to the program.
 * @return void.
 */
void	check_main_args(int ac)
{
	if (ac != 1)
	{
		ft_putendl_fd("do not add parameters to executable", 1);
		exit(0);
	}
	get_shell()->default_path = NULL;
}

/* [] Check main_args
    [] if ac != 1
		[] printf("do not add parameters to executable");
		[] exit(0) ou exit (1)
	[if !env
			handle_env_i
	[]else
			shell.env = array_dup(env);

*/

/**
 * @return address of static t_shell struct.
 */
t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}
