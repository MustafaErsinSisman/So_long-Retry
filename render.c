/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:41:15 by musisman          #+#    #+#             */
/*   Updated: 2026/04/09 12:41:15 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!game->wall_0 || !game->wall_1 || !game->player
		|| !game->key || !game->door0 || !game->door1)
		error(ERR_IMG);
}

static void	put_image(t_game *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, img, col * 64, row * 64);
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
			else
				put_image(game, game->wall_0, row, col);
			if (game->map[row][col] == 'P')
				put_image(game, game->player, row, col);
			else if (game->map[row][col] == 'C')
				put_image(game, game->key, row, col);
			else if (game->map[row][col] == 'E')
				put_image(game, game->door1, row, col);
		}
	}
}
