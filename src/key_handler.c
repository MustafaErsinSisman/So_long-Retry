/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:08:45 by musisman          #+#    #+#             */
/*   Updated: 2026/04/14 16:08:45 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_game(t_game *game)
{
	if (game->wall_0)
		mlx_destroy_image(game->mlx, game->wall_0);
	if (game->wall_1)
		mlx_destroy_image(game->mlx, game->wall_1);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->key)
		mlx_destroy_image(game->mlx, game->key);
	if (game->door0)
		mlx_destroy_image(game->mlx, game->door0);
	if (game->door1)
		mlx_destroy_image(game->mlx, game->door1);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_printf("Game closed. Total moves: %d\n", game->move_count);
	free(game->mlx);
	ft_free();
	exit(0);
}

static int	is_valid_move(t_game *game, int new_row, int new_col)
{
	if (game->map[new_row][new_col] == '1')
		return (message(MSG_WLL, -1));
	if (game->map[new_row][new_col] == 'E')
	{
		if (game->collected == game->coin_count)
		{
			message(MSG_WIN, -1);
			close_game(game);
		}
		else
			return (message(MSG_EXT, -1));
	}
	if (game->map[new_row][new_col] == 'C')
	{
		game->collected++;
		message(MSG_CON, game->collected);
		if (game->collected == game->coin_count)
		{
			message(MSG_COL, -1);
			put_image(game, game->door0, game->e_row, game->e_col);
		}
	}
	return (0);
}

static void	move_player(t_game *game, int row_change, int col_change)
{
	int	new_row;
	int	new_col;

	new_row = game->p_row + row_change;
	new_col = game->p_col + col_change;
	if (is_valid_move(game, new_row, new_col))
		return ;
	game->map[game->p_row][game->p_col] = '0';
	game->map[new_row][new_col] = 'P';
	put_image(game, game->wall_0, game->p_row, game->p_col);
	put_image(game, game->player, new_row, new_col);
	game->p_row = new_row;
	game->p_col = new_col;
	game->move_count++;
	message(MSG_MOV, game->move_count);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, -1, 0);
	else if (keycode == KEY_S)
		move_player(game, 1, 0);
	else if (keycode == KEY_A)
		move_player(game, 0, -1);
	else if (keycode == KEY_D)
		move_player(game, 0, 1);
	return (0);
}
