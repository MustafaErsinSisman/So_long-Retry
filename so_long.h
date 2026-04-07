/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:15:08 by musisman          #+#    #+#             */
/*   Updated: 2026/03/27 15:15:08 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./collector/collector.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_ARG "Wrong argument!\n"
# define ERR_ASS "Wrong asset!\n"
# define ERR_CNT "Wrong count of P, E or C!\n"
# define ERR_EMP "Empty map!\n"
# define ERR_MAP "Map is not valid!\n"
# define ERR_OPN "File couldn't open!\n"
# define ERR_REC "Map is not rectengular!\n"
# define ERR_WAL "Map is not close with wall!\n"

// silinecek

# include <stdio.h>

//

char	**read_ber_file(char *ber);
char	**check_map(char **ber);
void	flood_fill(char **map);
void	error(char *err);
#endif