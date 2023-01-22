/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:47 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/22 17:47:22 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*This global constant holds the tuples to add to a x/y coordinate
for each of the directions*/
const int	g_directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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
	altogether = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		perror("Error, invalid file");
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

/*This function checks each adjacent cell to the given cell on 
the matrix for a valid path and if it finds it, it will add it to the queue
@param matrix the two dimensional matrix to be checked for valid cells
@param cell the tuple that will be checked for adjacent valid cells
@param queue the linked list that holds the valid cells*/
void	adjacent(char **matrix, t_par *cell, t_list **queue)
{
	int	i;
	int	rows;
	int	a;
	int	b;

	rows = 0;
	while (matrix[rows])
		rows++;
	i = 0;
	while (i < 4)
	{
		a = g_directions[i][0] + cell->y;
		b = g_directions[i][1] + cell->x;
		if (a >= 0 && b >= 0 && a < rows && b < (int)ft_strlen(matrix[0])
			&& matrix[a][b] != 'X' && matrix[a][b] != '1')
			ft_lstadd_back(queue, ft_lstnew(newpar(b, a)));
		i++;
	}
}

/*This function checks to see if there is a path from
the starting point (start) to the end point (end) in the
given matrix. It creates a queue and adds the start point
to it. It then iterates through the queue, marking off
each point it visits with an 'X' and adding any adjacent points
to the queue. If it reaches the end point,
it returns 1, otherwise it returns 0.*/
int	is_path(char **matrix, t_par *start, t_par *end)
{
	t_list	*queue;
	t_par	*temp;
	char	**layout;

	layout = ft_matrdup(matrix);
	queue = ft_lstnew(newpar(start->x, start->y));
	while (queue)
	{
		temp = (t_par *) ft_lstpop(&queue);
		layout[temp->y][temp->x] = 'X';
		if (temp->x == end->x && temp->y == end->y)
		{
			free(temp);
			free_list(queue);
			free_matrix(layout);
			return (1);
		}
		adjacent(layout, temp, &queue);
		free(temp);
	}
	free_matrix(layout);
	free_list(queue);
	return (0);
}

int	is_correct(t_map **map)
{
	int		rows;
	int		j;

	rows = 0;
	while ((*map)->layout[rows])
		if ((int)ft_strlen((*map)->layout[rows++]) != (*map)->width)
			return (map_error("Error, the map isn't rectangular"));
	j = 0;
	while ((*map)->layout[0][j])
		if ((*map)->layout[0][j] != '1' || (*map)->layout[rows - 1][j++] != '1')
			return (map_error("Error, the walls aren't surrounding the map"));
	j = 0;
	while ((*map)->layout[j])
		if ((*map)->layout[j][0] != '1' || \
		(*map)->layout[j++][(*map)->width - 1] != '1')
			return (map_error("Error, the walls aren't surrounding the map"));
	if (!check_chars((*map)))
		return (0);
	if (!is_path((*map)->layout, (*map)->player, (*map)->exit))
		return (map_error("Error, invalid path"));
	if (!is_path_coll((*map)))
		return (map_error("Error, not all collectibles are reachabe"));
	return (1);
}
