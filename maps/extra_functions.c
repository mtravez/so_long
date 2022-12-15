/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:39:41 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/15 19:24:51 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "map.h"

int	check_paths(t_map *map)
{
	char	**matrix;
	
	matrix = ft_matrdup(map->layout);
	if (!is_path(matrix, map->player, map->exit))
		return (0);
	free(matrix);
	if (!is_path_coll(map))
		return (0);
	return (1);
}

int	get_exit_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (how_many_chars(map->layout, 'E') != 1)
		return (0);
	if (how_many_chars(map->layout, 'P' != 1))
		return (0);
	if (!how_many_chars(map->layout, 'C'))
		return (0);
	return (1);
}