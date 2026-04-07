/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:26:25 by musisman          #+#    #+#             */
/*   Updated: 2026/04/06 15:26:25 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line_count(char *ber)
{
	int		fd;
	int		count;
	char	*line;

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

static void	is_it_ber_file(char *ber)
{
	size_t	len;

	len = ft_strlen(ber);
	if (len < 4)
		error(ERR_ARG);
	if (ft_strncmp(&ber[len - 4], ".ber", 4))
		error(ERR_ARG);
}

static void	remove_unnecessary_char(char *line)
{
	size_t	len;
	int		i;

	if (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		i = ft_strlen(line);
		while (line[--i] && i > 0)
		{
			if (ft_isspace(line[i]))
				line[i] = '\0';
			if (ft_isprint(line[i]))
				break ;
		}
	}
}

char	**read_ber_file(char *ber)
{
	char	**ber_file;
	int		fd;
	int		line_count;
	int		i;

	is_it_ber_file(ber);
	line_count = get_line_count(ber);
	if (line_count == 0)
		error(ERR_EMP);
	ber_file = ft_calloc(line_count + 1, sizeof(char *));
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		error(ERR_OPN);
	i = -1;
	while (++i < line_count)
	{
		ber_file[i] = get_next_line(fd);
		remove_unnecessary_char(ber_file[i]);
	}
	ber_file[i] = NULL;
	close(fd);
	return (ber_file);
}
