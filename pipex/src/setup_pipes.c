/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:29:41 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:49 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	setup_envp(t_pipes **exec, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			(*exec)[0].path_var = &envp[i][5];
			break ;
		}
		i++;
	}
	if (!(envp[i]))
	{
		write(2, "No PATH variable found\n", 23);
		return ;
	}
}

static char	*flag_result(char *av)
{
	char	*str;
	int		i;

	str = av;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] && !(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	return (str + i);
}

static char	*cmd_result(char *av)
{
	char	*str;
	int		i;
	int		j;

	str = av;
	i = 0;
	j = 0;
	while (av[i] && (av[i] == ' ' || av[i] == '\n' || av[i] == '\t'
			|| av[i] == '\v' || av[i] == '\f' || av[i] == '\r'))
		i++;
	if (!(av[i]))
		return (str);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i + j] && !(str[i + j] == ' ' || str[i + j] == '\n'
			|| str[i + j] == '\t'
			|| str[i + j] == '\v' || str[i + j] == '\f' || str[i + j] == '\r'))
		j++;
	str[j] = '\0';
	return (str + i);
}

void	setup_pipes(int ac, char **av, t_pipes **exec, char **envp)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	if (!ft_strcmp(av[1], "here_doc"))
		i = 3;
	*exec = (t_pipes *)ft_calloc(ac + 1, sizeof(t_pipes));
	if (!(*exec))
		return ;
	while (j < ac)
	{
		if (av[i][1])
			(*exec)[j].flags = flag_result(av[i]);
		(*exec)[j].cmd = cmd_result(av[i]);
		(*exec)[j].index = j;
		i++;
		j++;
	}
	(*exec)[j].value = 1;
	setup_envp(exec, envp);
}
