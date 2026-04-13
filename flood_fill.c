/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:37:44 by musisman          #+#    #+#             */
/*   Updated: 2026/04/07 12:37:44 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map)
{
	char	**temp;
	int		len_line;
	int		i;

	i = -1;
	len_line = 0;
	while (map[++i])
		len_line++;
	temp = ft_calloc(len_line + 1, sizeof(char *));
	i = -1;
	while (map[++i])
		temp[i] = ft_strdup(map[i]);
	temp[i] = NULL;
	return (temp);
}

static void	find_player(char **map, int p_coordinate[2])
{
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == 'P')
			{
				p_coordinate[0] = row;
				p_coordinate[1] = col;
				break ;
			}
		}
	}
}

static void	fill(char **map, int row, int col)
{
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	map[row][col] = 'F';
	fill(map, row + 1, col);
	fill(map, row - 1, col);
	fill(map, row, col + 1);
	fill(map, row, col - 1);
}

static void	is_it_fiilled(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				error(ERR_MAP);
		}
	}
}

char	**flood_fill(char **map)
{
	char	**temp;
	int		p_rc[2];

	temp = copy_map(map);
	find_player(temp, p_rc);
	fill(temp, p_rc[0], p_rc[1]);
	is_it_fiilled(temp);
	return (map);
}
