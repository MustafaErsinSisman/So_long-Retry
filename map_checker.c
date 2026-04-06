/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:28:09 by musisman          #+#    #+#             */
/*   Updated: 2026/04/06 15:28:09 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_it_rectengular(char** ber)
{
	size_t	f_line_len;
	size_t	line_len;
	size_t	i;
	size_t	j;

	i = -1;
	f_line_len = 0;
	while (ber[++i])
	{
		j = -1;
		line_len = 0;
		while (ber[i][++j])
		{
			if (ft_isspace(ber[i][j]))
				break;
			if (ft_isprint(ber[i][j]) && i == 0)
				f_line_len++;
			else if (ft_isprint(ber[i][j]))
				line_len++;
		}
		if (line_len != f_line_len && i != 0)
			error(ERR_REC);
	}
}

static void	is_is_asset(char** ber)
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (ber[++i])
	{
		j = -1;
		while (ber[i][++j])
		{
			c = ber[i][j];
			if (!(c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C'))
				error(ERR_ASS);
		}
	}
}

void	is_it_enclosed(char** ber)
{
	int	i;
	int	j;

	i = -1;
	while (ber[++i])
	{
		j = -1;
		while (ber[i][++j])
		{
			if (i == 0 || ber[i + 1] == NULL || j == 0 || ber[i][j + 1] == '\0')
			{
				if (ber[i][j] != '1')
					error(ERR_WAL);
			}
		}
	}
}

void check_map(char** ber)
{
	is_it_rectengular(ber);
	is_is_asset(ber);
	is_it_enclosed(ber);
}
