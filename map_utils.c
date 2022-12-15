/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:13:28 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/13 13:34:49 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function gets the number of rows in a file using
get_next_line. It opens and closes the file when it is done.
@param file the path to the file in String form*/
static int get_rows(char *file)
{
	char	*line;
	int		rows;
	int		fd;

	fd = open (file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		map_error("Error, invalid file");
	while(line)
	{
		line = get_next_line(fd);
		rows++;
	}
	close(fd);
	return(rows);
}

/*This function turns a file into a two dimensional array matrix
in which each row is a line of the file.
@param file the path to the file in String form*/
char	**get_map(char *file)
{
	char	*map;
	int		i;
	int		rows;
	int		fd;
	char	*temp;
	
	rows = get_rows(file);
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	map = (char *) ft_calloc(ft_strlen(temp), rows);
	i = 0;
	while (temp)
	{
		map = ft_strjoin(map, temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (ft_split(map, '\n'));
}

int		ft_ptr_strlen(char **strptr)
{
	int	i;

	i = 0;
	while (strptr[i])
		i++;
	return (i);
}

t_map	new_map()
{
	t_map	map;
	
	map.coll = 0;
	map.exit[0] = 0;
	map.exit[1] = 0;
	map.l_walls = 0;
	map.s_walls = 0;
	map.player[0] = 0;
	map.player[1] = 0;
	return (map);
}