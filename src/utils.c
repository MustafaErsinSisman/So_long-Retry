/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:29:24 by musisman          #+#    #+#             */
/*   Updated: 2026/04/06 15:29:24 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(char *err)
{
	ft_printf("Error\n");
	ft_printf("%s\n", err);
	ft_free();
	exit(1);
}

int	message(char *msg, int count)
{
	if (count >= 0)
		ft_printf("%s: %d\n", msg, count);
	else
		ft_printf("%s\n", msg);
	return (1);
}
