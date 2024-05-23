/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:53:43 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:06:03 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_pipes
{
	pid_t	pid;
	int		fd;
	char	*cmd;
	char	*flags;
	int		value;
	int		index;
	char	*path_var;
}					t_pipes;

/* LIBFT UTILS */

size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *str, int c, size_t n);
int		ft_strcmp(char *str1, char *str2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);

/* PIPEX */

void	close_pipes(int **pipe_fd, t_pipes *exec);
void	free_pipes(int ***pipe_fd, int index, t_pipes **exec);
int		open_pipes(int num_pipes, int **pipe_fd);
void	setup_pipes(int ac, char **av, t_pipes **exec, char **envp);
void	pipex(t_pipes **exec, int ac, char **av, char **envp);
void	execute_pipes(t_pipes **exec, int ac, char **envp, char **av);
void	execute_command(t_pipes *exec, char **envp, char *cmd, int index);
void	not_enough_args(int ac, char **av);
void	error_waiting_children(t_pipes **exec);

/* UTILS */
char	*get_next_line(int fd);
void	check_cmd(t_pipes **exec, char **envp, int index);
int		last_cmd(t_pipes *exec);
void	alloc_mem(int ***pipe_fd, t_pipes **exec);
void	waiting_for_children(t_pipes **exec, int **pipe_fd);
int		ft_strlen2(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);

#endif
