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

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		error(ERR_ARG);
	mlx_processes(flood_fill(check_map(read_ber_file(av[1]))));
	ft_free();
	return (0);
}
