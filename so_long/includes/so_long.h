/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:48:00 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 17:48:00 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

/* -------- KEY VALUES -------- */
# define KEY_PRESS 2
# define RIGHT_KEY 100
# define LEFT_KEY 97
# define DOWN_KEY 115
# define UP_KEY 119
# define ESC_KEY 65307
# define WIN_CLOSE 17

/* -------- MAP VALUES -------- */
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define EMPTY '0'
# define SQUARE 32

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

/* -------- STRUCTS -------- */

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			collectibles;
	t_vector	player;
}	t_map;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_size;
	int		fd;
	int		can_exit;
	t_map	map;
	size_t	moves;
}	t_program;

/* -------- SRC -------- */
void	check_map(char *file, t_program *game);
void	read_map(char *file, t_program *game);
void	new_window(t_program *game);
void	ft_free(t_program *game, char *msg);
void	render_map(t_program game);
void	render_image(t_program game, int x, int y);
int		close_window(t_program *game);
int		ft_input(int key, void	*param);
char	*ft_get_path(char c, int can_exit);
void	ft_swap(char *a, char *b);
void	move_up(t_program *game);
void	move_down(t_program *game);
void	move_left(t_program *game);
void	move_right(t_program *game);
void	get_player_position(t_program *game);
void	get_collectibles(t_program *game);
void	free_resources(t_program *game);

/* -------- CHECKER -------- */
int		check_extension(const char *file, const char *ext);
int		check_rectangular(t_program game);
int		check_characters(t_program game);
int		check_player(t_program game);
int		check_walls(t_program *game);
int		check_ecp(t_program game);
int		validate_path(t_map *map);
int		map_len(int fd);
char	*remove_newline(char *line);

/* -------- UTILS -------- */
void	copy_map(char **copy, t_map *map);
void	ft_free_map(char **map, int rows);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

/* -------- ERROR -------- */
void    error_extension(t_program *game, char *file);
void    error_rectangular(t_program *game, char *file);
void    error_characters(t_program *game, char *file);
void    error_player(t_program *game, char *file);
void    error_walls(t_program *game, char *file);
void    error_ecp(t_program *game, char *file);

#endif
