/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:48:48 by musisman          #+#    #+#             */
/*   Updated: 2026/04/20 15:48:48 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->wall_0 = mlx_xpm_file_to_image(game->mlx, "xpms/wall0.xpm", &w, &h);
	game->wall_1 = mlx_xpm_file_to_image(game->mlx, "xpms/wall1.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx, "xpms/player.xpm", &w, &h);
	game->key = mlx_xpm_file_to_image(game->mlx, "xpms/key.xpm", &w, &h);
	game->door0 = mlx_xpm_file_to_image(game->mlx, "xpms/door0.xpm", &w, &h);
	game->door1 = mlx_xpm_file_to_image(game->mlx, "xpms/door1.xpm", &w, &h);
	game->enemy0 = mlx_xpm_file_to_image(game->mlx, "xpms/enemy0.xpm", &w, &h);
	game->enemy1 = mlx_xpm_file_to_image(game->mlx, "xpms/enemy1.xpm", &w, &h);
	if (!game->wall_0 || !game->wall_1
		|| !game->player || !game->key
		|| !game->door0 || !game->door1
		|| !game->enemy0 || !game->enemy1)
		error(ERR_IMG);
}

void	render_map(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == '1')
				put_image(game, game->wall_1, row, col);
			else if (game->map[row][col] == '0')
				put_image(game, game->wall_0, row, col);
			else if (game->map[row][col] == 'P')
				put_image(game, game->player, row, col);
			else if (game->map[row][col] == 'C')
				put_image(game, game->key, row, col);
			else if (game->map[row][col] == 'E')
				put_image(game, game->door1, row, col);
			else if (game->map[row][col] == 'V')
				put_image(game, game->enemy0, row, col);
		}
	}
}

static void	render_enemies(t_game *game)
{
	int	r;
	int	c;

	r = -1;
	while (++r < game->map_h)
	{
		c = -1;
		while (++c < game->map_w)
		{
			if (game->map[r][c] == 'V')
			{
				if (game->enemy_state == 0)
					put_image(game, game->enemy0, r, c);
				else
					put_image(game, game->enemy1, r, c);
			}
		}
	}
}

int	animate_sprites(t_game *game)
{
	game->timer++;
	if (game->timer > 40000)
	{
		game->timer = 0;
		if (game->enemy_state == 0)
			game->enemy_state = 1;
		else
			game->enemy_state = 0;
		render_enemies(game);
	}
	return (0);
}
