/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:13:43 by musisman          #+#    #+#             */
/*   Updated: 2026/04/07 14:13:43 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_size(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	game->map_h = i;
	game->map_w = ft_strlen(map[0]);
}

void	mlx_processes(char **map)
{
	t_game	game;

	map_size(map, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error(ERR_INI);
	game.win = mlx_new_window(game.mlx, game.map_w * 64, game.map_h * 64, "So_long");
	if (!game.win)
		error(ERR_WIN);
	mlx_loop(game.mlx);
}
