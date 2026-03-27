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

char**	read_ber_file(char* ber)
{
	char**	ber_file;
	size_t	i;

	ber_file = ft_malloc(ft_strlen(ber));
	i = -1;
	while (ber_file[++i])
		ber_file[i] = get_next_line();
	return (ber_file);
}

int	main(int ac, char **av)
{
	if(ac != 2)
		error(ERR_ARG);
	read_ber_file(av[1]);
	ft_free();
	return (0);
}
