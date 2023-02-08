/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:47 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/08 13:14:31 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*This function reads the given path and transforms the contents of the 
file into a two dimentional character matrix
@param path path to the file*/
char	**get_map_matrix(char *path)
{
	char	*line;
	int		fd;
	char	*altogether;
	char	**matrix;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ((char **)map_error("Error\nFailed to create the map."));
	altogether = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		perror("Error\nInvalid file");
		return (NULL);
	}
	while (line)
	{
		altogether = ft_strjoin_gnl(altogether, line);
		line = get_next_line(fd);
	}
	close(fd);
	matrix = ft_split(altogether, '\n');
	free(altogether);
	return (matrix);
}

/*This function checks every condition for the map and
returns 1 if it complies, 0 if not*/
int	is_correct(t_map **map)
{
	int		rows;
	int		j;

	rows = 0;
	while ((*map)->layout[rows])
		if ((int)ft_strlen((*map)->layout[rows++]) != (*map)->width)
			return ((int)map_error("Error\nThe map isn't rectangular"));
	j = 0;
	while ((*map)->layout[0][j])
		if ((*map)->layout[0][j] != '1' || (*map)->layout[rows - 1][j++] != '1')
			return ((int)map_error \
			("Error\nThe walls aren't surrounding the map"));
	j = 0;
	while ((*map)->layout[j])
		if ((*map)->layout[j][0] != '1' || \
		(*map)->layout[j++][(*map)->width - 1] != '1')
			return ((int)map_error \
			("Error\nThe walls aren't surrounding the map"));
	if (!check_chars((*map)))
		return (0);
	if (!is_path_ultimate(*map))
		return ((int)map_error("Error\nNot valid path from player"));
	return (1);
}
