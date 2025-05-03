/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_auxiliars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:18:12 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:53:03 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks whether the last input redirection is an infile or a
 * here-document.
 * Iterates through all input redirections of a command and determines
 * if the last one is a `HERE_DOC` or an `INFILE`. Returns 0 if it's an
 * `INFILE`, and 1 if it's a `HERE_DOC`.
 *
 * @param cmd the command to check.
 *
 * @return 0 if the last input redirection is an `INFILE`,
	1 if it's a `HERE_DOC`.
 */
int	last_is_infile(t_cmd *cmd)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (cmd->redirections[i])
	{
		if (cmd->redirections[i]->type == INFILE)
			b = 0;
		else if (cmd->redirections[i]->type == HERE_DOC)
			b = 1;
		i++;
	}
	return (b);
}

/**
 * @brief Opens an infile and returns its file descriptor.
 *
 * Attempts to open the file in read-only mode. If the file cannot be opened,
 * prints an error message and returns -1.
 *
 * @param infile the name of the input file to open.
 *
 * @return the file descriptor on success, -1 on failure.
 */
int	get_fd_infile(char *infile)
{
	int	fd_infile;

	fd_infile = open(infile, O_RDONLY);
	if (fd_infile == -1)
	{
		printf("Error opening infile: %s\n", infile);
		return (-1);
	}
	return (fd_infile);
}
