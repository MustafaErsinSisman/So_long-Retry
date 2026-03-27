/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <musisman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:30:54 by musisman          #+#    #+#             */
/*   Updated: 2026/03/27 14:30:54 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTOR_H
# define COLLECTOR_H

# include "../Libft/libft.h"

typedef struct s_memblock
{
	void				*data;
	size_t				size;
	struct s_memblock	**head;
	struct s_memblock	*next;

}						t_memblock;

t_memblock	*ft_add_new_block(void *data, size_t size);
void		ft_clear_all_blocks(t_memblock **head);
void		*ft_exit(void);
void		*ft_malloc(size_t size);
void		*ft_calloc(size_t count, size_t size);
void		ft_free(void);

#endif