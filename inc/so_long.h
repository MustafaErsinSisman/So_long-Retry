/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:15:08 by musisman          #+#    #+#             */
/*   Updated: 2026/03/27 15:15:08 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "../collector/collector.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define MSG_COL "All coins collected! Find the exit!"
# define MSG_CON "Coins collected"
# define MSG_EXT "Collect all coins to exit!"
# define MSG_MOV "Move count"
# define MSG_WIN "Congratulations! You won!"
# define MSG_WLL "Am I a ghost? I can't walk through walls!"

# define ERR_ARG "Wrong argument!\n"
# define ERR_ASS "Wrong asset!\n"
# define ERR_CNT "Wrong count of P, E or C!\n"
# define ERR_EMP "Empty map!\n"
# define ERR_IMG "Could not load images!\n"
# define ERR_INI "MLX initialization failed!\n"
# define ERR_MAP "Map is not valid!\n"
# define ERR_OPN "File couldn't open!\n"
# define ERR_REC "Map is not rectengular!\n"
# define ERR_WAL "Map is not close with wall!\n"
# define ERR_WIN "Window creation failed!\n"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	void	*wall_0;
	void	*wall_1;
	void	*player;
	void	*key;
	void	*door0;
	void	*door1;
	int		p_row;
	int		p_col;
	int		coin_count;
	int		move_count;
	int		collected;
	int		e_row;
	int		e_col;
}	t_game;

char	**read_ber_file(char *ber);
char	**check_map(char **ber);
char	**flood_fill(char **map);
void	mlx_processes(char **map);
void	load_images(t_game *game);
void	init_game_vars(t_game *game);
void	put_image(t_game *game, void *img, int row, int col);
void	render_map(t_game *game);
int		close_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	error(char *err);
int		message(char *msg, int count);

#endif