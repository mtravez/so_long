/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:47 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/17 18:23:35 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	fd = open(path, O_RDONLY);
	altogether = NULL;
	line = get_next_line(fd);
	if (!line)
		perror("Error, invalid file");
	while (line)
	{
		altogether = ft_strjoin_gnl(altogether, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_split(altogether, '\n'));
}

/*This function creates a new tuple with the corresponding
variables as parameters
@param x the x integer of the pair
@param y the y integer of the pair*/
t_par *newpar(int x, int y)
{
	t_par *par;

	par = malloc(sizeof(t_par *));
	par->x = x;
	par->y = y;
	return (par);
}

/*This function checks each adjacent cell to the given cell on 
the matrix for a valid path and if it finds it, it will add it to the queue
@param matrix the two dimensional matrix to be checked for valid cells
@param cell the tuple that will be checked for adjacent valid cells
@param queue the linked list that holds the valid cells*/
void	adjacent(char **matrix, t_par *cell, t_list **queue)
{
	int			i;
	int			rows;

	rows = 0;
	while (matrix[rows])
		rows++;
	i = 0;
	while (i < 4)
	{
		int a = g_directions[i][0] + cell->y;
		int b = g_directions[i][1] + cell->x;
		if (a >= 0 && b >= 0 && a < rows && b < ft_strlen(matrix[0])
			&& matrix[a][b] != 'X' && matrix[a][b] != '1')
			ft_lstadd_back(queue, ft_lstnew(newpar(b, a)));
		i++;
	}
}

/*This function checks to see if there is a path from the starting 
point (start) to the end point (end) in the given matrix. It creates 
a queue and adds the start point to it. It then iterates through the queue, 
marking off each point it visits with an 'X' and adding any adjacent points
to the queue. If it reaches the end point, it returns 1, otherwise it returns 0.*/
int	is_path(char **matrix, t_par *start, t_par *end)
{
	t_list	*queue;
	t_par	*number;
	t_par	*temp;
	int		i;
	char	**layout;

	layout = ft_matrdup(matrix);
	queue = ft_lstnew(start);
	i = 0;
	while (queue)
	{
		i++;
		temp = (t_par *) queue->content;
		number = newpar(temp->x, temp->y);
		queue = queue->next;
		layout[temp->y][temp->x] = 'X';
		if (temp->x == end->x && temp->y == end->y)
			return (1);
		adjacent(layout, number, &queue);
	}
	free(layout);
	return (0);
}

t_map	*is_correct(char **matrix)
{
	int		rows;
	int		j;
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	rows = 0;
	map->layout = ft_matrdup(matrix);
	map->width = ft_strlen(matrix[0]);
	map->coll = get_collectibles(matrix);
	while (matrix[rows])
		if (ft_strlen(matrix[rows++]) != map->width)
		{
			perror("Error, the map isn't rectangular");
			return (NULL);
		}
	map->length = rows;
	j = 0;
	while (matrix[0][j])
		if (matrix[0][j++] != '1')
		{
			perror("Error, the walls aren't surrounding the map");
			return (NULL);
		}
	if (!check_chars(map))
	{
		ft_printf("hi");
		return (NULL);
	}
	get_exit_player(&map);
	if (!is_path(matrix, map->player, map->exit))
	{
		perror("Error, invalid path");
		return (NULL);
	}
	if (!is_path_coll(map))
	{
		perror("Error, not all collectibles are reachabe");
		return (NULL);
	}
	return (map);
}

int	works(char *path)
{
	char **matrix = get_map_matrix(path);
	t_map *map = is_correct(matrix);
	if (map == NULL)
		return (0);
	return (1);
}