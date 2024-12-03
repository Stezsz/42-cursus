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
void	check_map(char *file_name, t_program *game);
void	error_filename(char *file_name);
void	get_map(char *file_name, t_program *game);
int		check_filename(const char *map, const char *to_find);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

/* ---- get_next_line functions ---- */
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);

#endif
