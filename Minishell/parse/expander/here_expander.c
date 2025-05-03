/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:36:40 by strodrig          #+#    #+#             */
/*   Updated: 2025/04/25 20:36:40 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Expands variables in a here-document line.
 *
 * Iterates through the given `line`, processing `$` characters to expand
 * variables. The expanded result is stored in a new string, replacing the
 * original `line`. If no expansion occurs, `line` is set to `NULL`.
 *
 * @param line Pointer to the string being expanded.
 *
 * @return void.
 *
 * Auxiliary functions: process_dollar, update_str, free.
 */
void	here_expander(char **line)
{
	int		i;
	char	*update;

	update = NULL;
	i = 0;
	while (*line && (*line)[i])
	{
		if ((*line)[i] == '$')
		{
			process_dollar(&i, *line + i, &update);
		}
		else
			update_str(&update, *line, i++, 1);
	}
	if (*line)
		free(*line);
	if (update)
		(*line) = update;
	else
		*line = NULL;
}
