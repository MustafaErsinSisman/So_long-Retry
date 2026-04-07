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

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
		error(ERR_ARG);
	check_map(read_ber_file(av[1]));
	ft_free();
	return (0);
}
