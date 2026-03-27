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

int	main(int ac, char **av)
{
	char	**map;

	if(ac != 2)
		error(ERR_ARG);
	map = read_ber_file(av[1]);
	write(1, map[1], ft_strlen(map[1]));
	ft_free();
	return (0);
}
