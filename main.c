/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:59:17 by musisman          #+#    #+#             */
/*   Updated: 2026/03/27 14:59:17 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	error(char* err)
{
	write(2, err, ft_strlen(err));
	ft_free();
	exit(1);
}

int	get_line_count(char *ber)
{
	int		fd;
	int		count;
	char		*line;

	count = 0;
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		error(ERR_OPN);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_ber_file(char *ber)
{
	char	**ber_file;
	int		fd;
	int		line_count;
	int		i;

	line_count = get_line_count(ber);
	if (line_count == 0)
		error(ERR_EMP);
	ber_file = ft_calloc(line_count + 1, sizeof(char *));
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		error(ERR_OPN);
	i = -1;
	while (++i < line_count)
		ber_file[i] = get_next_line(fd);
	ber_file[i] = NULL;
	close(fd);
	return (ber_file);
}

int is_it_asset(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	else
		return(0);
}

int is_it_rectengular(char** ber)
{
	int	i;
	int	first_line_asset;

	i = -1;
	first_line_asset = 0;
	while (ber[0][++i])
	{
		if (is_it_asset(ber[0][i]))
			first_line_asset++;
	}
	while (ber[++i])
	{
		if (ft_strlen(ber[i]) != ft_strlen(ber[i]))
			return (0);
	}
	return (1);
}

void check_map(char** ber)
{
	if (!is_it_rectengular(ber))
		error(ERR_REC);

}

int	main(int ac, char **av)
{
	char	**map;

	if(ac != 2)
		error(ERR_ARG);
	check_map(read_ber_file(av[1]));
	ft_free();
	return (0);
}
