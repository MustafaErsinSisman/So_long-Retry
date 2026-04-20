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

static void	draw_num_hud(t_game *g, char *pref, int n, int y)
{
	char	buf[64];
	char	rev[16];
	int		i;
	int		len;

	i = -1;
	while (pref[++i])
		buf[i] = pref[i];
	if (n == 0)
		buf[i++] = '0';
	len = 0;
	while (n > 0)
	{
		rev[len++] = (n % 10) + '0';
		n /= 10;
	}
	while (len > 0)
		buf[i++] = rev[--len];
	buf[i] = '\0';
	mlx_string_put(g->mlx, g->win, 15, y, g->color, buf);
}

int	update_hud(t_game *g, char *msg, int msg_color)
{
	clear_hud_background(g);
	if (msg != NULL)
		mlx_string_put(g->mlx, g->win, 15, 20, msg_color, msg);
	else
	{
		g->color = C_MOV;
		draw_num_hud(g, "Moves: ", g->move_count, 20);
		if (g->collected == g->coin_count)
			mlx_string_put(g->mlx, g->win, 15, 40, C_EXT, MSG_COL);
		else
		{
			g->color = C_COL;
			draw_num_hud(g, "Keys: ", g->collected, 40);
		}
	}
	return (1);
}
