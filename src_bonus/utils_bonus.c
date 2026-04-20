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

#include "../inc_bonus/so_long_bonus.h"

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
