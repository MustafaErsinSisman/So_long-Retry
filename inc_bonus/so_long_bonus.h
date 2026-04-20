/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:46:11 by musisman          #+#    #+#             */
/*   Updated: 2026/04/20 15:46:11 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "collector.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define RST "\033[0m"

# define C_MOV 0xFFFFFF
# define C_WAR 0xFF0000
# define C_COL 0xFFFF00
# define C_EXT 0x00FF00

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define MSG_COL "Keys collected"
# define MSG_EXT "Collect all keys to exit"
# define MSG_FIN "Game closed. Total moves"
# define MSG_KEY "Key count: "
# define MSG_MOV "Move count: "
# define MSG_OVR "Game over!"
# define MSG_WIN "Congratulations! You won!"
# define MSG_WLL "Am I a ghost?"

# define ERR_ARG "Wrong argument!"
# define ERR_ASS "Wrong asset!"
# define ERR_CNT "Wrong count of P, E or C!"
# define ERR_EMP "Empty map!"
# define ERR_IMG "Could not load images!"
# define ERR_INI "MLX initialization failed!"
# define ERR_MAP "Map is not valid!"
# define ERR_OPN "File couldn't open!"
# define ERR_REC "Map is not rectengular!"
# define ERR_WAL "Map is not close with wall!"
# define ERR_WIN "Window creation failed!"

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
	void	*enemy;
	int		p_row;
	int		p_col;
	int		coin_count;
	int		move_count;
	int		collected;
	int		e_row;
	int		e_col;
	int		color;
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
int		message(char *msg, int count, char *color);
int		update_hud(t_game *game, char *center_msg, int center_color);

#endif