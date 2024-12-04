/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:35:18 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/02 13:35:18 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "../ft_printf/ft_printf.h"

/* ------- KEY VALUES ------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define UP_KEY 13
# define DOWN_KEY 1
# define ESC_KEY 53
# define WIN_CLOSE 17

/* ------- MAP ------- */
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define FLOOR '0'

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	char		**map;
	int			col;
	int			row;
	int			collectibles;
	t_vector	player;
}				t_map;

typedef struct s_program
{
	void		*mlx; // Ponteiro para a conexão com o MLX (MiniLibX).
	void		*win_ptr; // Ponteiro para a janela criada.
	void		*img_ptr; // Ponteiro para a imagem a ser desenhada.
	int			img_size; // Tamanho da imagem (sprites).
	t_map		map; // Dados do mapa atual.
	int			fd; // File descriptor para o arquivo do mapa.
	int			can_exit; // Flag para indicar se o jogador pode sair.
	size_t		mv_count; // Contador de movimentos do jogador.
}				t_program;

/* ------- Checker -------*/
int		check_elements(t_program *game);
int		check_filename(const char *map, const char *to_find);
void	check_map(char *file_name, t_program *game);
int		check_rectangular(t_program game);
int		check_walls(t_program *game);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	get_map(char *file_name, t_program *game);
int		map_len(int fd);

/* ------- Src -------*/
void	free_map(t_program *game);
void	ft_free(t_program *game, char *msg);
void	ft_move_player(t_program *game, int x, int y);
int		ft_input(int key, void *param);
void	ft_render(t_program game);
void	ft_new_window(t_program *game);
int		ft_close(t_program *game);

/* ------- Error -------*/
void	error_filename(char *file_name);
void	error_walls(t_program *game, char *file_name);
void	error_rectangular(t_program *game, char *file_name);
void	error_elements(t_program *game, char *file_name);

/* ---- get_next_line functions ---- */
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);

#endif
