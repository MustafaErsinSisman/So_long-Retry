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

	game->img_wall_0 = mlx_xpm_file_to_image(game->mlx, "xpms/wall_0.xpm", &w, &h);
	game->img_wall_1 = mlx_xpm_file_to_image(game->mlx, "xpms/wall_1.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "xpms/player.xpm", &w, &h);
	game->img_key = mlx_xpm_file_to_image(game->mlx, "xpms/key.xpm", &w, &h);
	game->img_open_door = mlx_xpm_file_to_image(game->mlx, "xpms/open_door.xpm", &w, &h);
	game->img_close_door = mlx_xpm_file_to_image(game->mlx, "xpms/close_door.xpm", &w, &h);

	if (!game->img_wall_0 || !game->img_wall_1 || !game->img_player 
		|| !game->img_key || !game->img_open_door || !game->img_close_door)
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
				put_image(game, game->img_wall_1, row, col);
			else
				put_image(game, game->img_wall_0, row, col);
			if (game->map[row][col] == 'P')
				put_image(game, game->img_player, row, col);
			else if (game->map[row][col] == 'C')
				put_image(game, game->img_key, row, col);
			else if (game->map[row][col] == 'E')
				put_image(game, game->img_close_door, row, col);
		}
	}
}