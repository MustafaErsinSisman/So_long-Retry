/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:47:51 by musisman          #+#    #+#             */
/*   Updated: 2026/04/20 15:47:51 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		error(ERR_ARG);
	mlx_processes(flood_fill(check_map(read_ber_file(av[1]))));
	ft_free();
	return (0);
}
