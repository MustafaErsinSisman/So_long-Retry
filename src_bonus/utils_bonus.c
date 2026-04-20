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

static void	clear_hud_background(t_game *game)
{
	int	col;

	col = -1;
	while (++col < game->map_w)
		put_image(game, game->wall_1, 0, col);
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
