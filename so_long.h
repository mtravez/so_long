/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:59 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/20 17:54:50 by mtravez          ###   ########.fr       */
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

void	map_error(char *message);
void	draw_map(void *mlx, t_map *map);
int		is_correct(t_map **map);
t_map	*get_map(char *path);
#endif