/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_processes_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:48:40 by musisman          #+#    #+#             */
/*   Updated: 2026/04/20 15:48:40 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i;
	game->map_w = ft_strlen(game->map[0]);
}

static void	init_game_vars(t_game *game)
{
	int	row;
	int	col;

	game->move_count = 0;
	game->collected = 0;
	game->coin_count = 0;
	game->enemy_state = 0;
	game->timer = 0;
	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == 'P' || game->map[row][col] == 'E')
				set_assets_positions(game, row, col);
			if (game->map[row][col] == 'C')
				game->coin_count++;
		}
	}
}

static void	draw_num_hud(t_game *game, char *pref, int num, int y)
{
	char	buf[64];
	char	rev[16];
	int		i;
	int		len;

	i = -1;
	while (pref[++i])
		buf[i] = pref[i];
	if (num == 0)
		buf[i++] = '0';
	len = 0;
	while (num > 0)
	{
		rev[len++] = (num % 10) + '0';
		num /= 10;
	}
	while (len > 0)
		buf[i++] = rev[--len];
	buf[i] = '\0';
	mlx_string_put(game->mlx, game->win, 15, y, game->color, buf);
}

int	update_hud(t_game *game, char *msg, int msg_color)
{
	clear_hud_background(game);
	if (msg != NULL)
		mlx_string_put(game->mlx, game->win, 15, 20, msg_color, msg);
	else
	{
		game->color = C_MOV;
		draw_num_hud(game, MSG_MOV, game->move_count, 20);
		if (game->collected == game->coin_count)
			mlx_string_put(game->mlx, game->win, 15, 40, C_EXT, MSG_COL);
		else
		{
			game->color = C_COL;
			draw_num_hud(game, MSG_KEY, game->collected, 40);
		}
	}
	return (1);
}

void	mlx_processes(char **map)
{
	t_game	game;

	game.map = map;
	map_size(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error(ERR_INI);
	game.win = mlx_new_window(game.mlx, game.map_w * 64,
			game.map_h * 64, "So_long");
	if (!game.win)
		error(ERR_WIN);
	load_images(&game);
	init_game_vars(&game);
	render_map(&game);
	update_hud(&game, NULL, C_MOV);
	mlx_loop_hook(game.mlx, animate_sprites, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
}
