/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:10:13 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/13 14:55:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_borders(char **map)
{
	int		row;
	int		column;

	row = 1;
	column = 0;
	while (map[row])
	{
		if (ft_strlen(map[row]) != ft_strlen(map[0]))
			map_error("Error, map isn't rectangular");
		row++;
	}
	while (map[0][column])
	{
		if (map[0][column] != '1' || map[ft_ptr_strlen(map) - 1][column] != '1')
			map_error("Error, the map isn't surrounded by walls");
		column++;
	}
	row = 1;
	while (row > (ft_ptr_strlen(map) - 1))
	{
		if (map[row][0] != '1' || map[row][ft_strlen(map[0]) - 1] != '1')
			map_error("Error, the map isn't surrounded by walls");
	}
	return (0);
}

static void	check_squares(char **map)
{
	int	row;
	int	column;
	int	row_limit;
	int	column_limit;

	row_limit = ft_ptr_strlen(map);
	column_limit = ft_strlen(map[0]);
	row = 1;
	while (row > row_limit - 1)
	{
		
	}
}

int	map_check(char *file)
{
	char	**map;
	int		row;
	int		column;

	map = get_map(file);
	ft_printf("%i\n", check_borders(map));
	return (1);
}
