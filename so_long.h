/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:59 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/14 16:27:07 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "maps/map.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_player
{
	mlx_image_t *image;
	int	collectibles;
}	t_player;

int		map_check(char *file);
void	map_error(char *message);
int		ft_ptr_strlen(char **strptr);
char	**get_map(char *file);
t_map	new_map();
#endif