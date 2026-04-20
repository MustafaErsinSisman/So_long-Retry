/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:49:01 by musisman          #+#    #+#             */
/*   Updated: 2026/04/20 15:49:01 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *err)
{
	ft_printf("%sError%s\n", R, RST);
	ft_printf("%s%s%s\n", R, err, RST);
	ft_free();
	exit(1);
}

int	message(char *msg, int count, char *color)
{
	if (count >= 0)
		ft_printf("%s%s: %d%s\n", color, msg, count, RST);
	else
		ft_printf("%s%s%s\n", color, msg, RST);
	return (1);
}

void	clear_hud_background(t_game *game)
{
	int	col;

	col = -1;
	while (++col < game->map_w)
		put_image(game, game->wall_1, 0, col);
}

void	put_image(t_game *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, img, col * 64, row * 64);
}

void	set_assets_positions(t_game *game, int row, int col)
{
	if (game->map[row][col] == 'P')
	{
		game->p_row = row;
		game->p_col = col;
	}
	else if (game->map[row][col] == 'E')
	{
		game->e_row = row;
		game->e_col = col;
	}
}
