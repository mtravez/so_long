/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:46:13 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/08 19:36:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*This global constant holds the tuples to add to a x/y coordinate
for each of the directions*/
const int	g_directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

/*This function removes a cell from a list and reasigns the 
adjacent cells accordingly*/
void	remove_cell(t_list **head, t_list *to_remove)
{
	t_list	*temp;

	temp = *head;
	if (to_remove == *head)
	{
		*head = to_remove->next;
		free(to_remove->content);
		free(to_remove);
		return ;
	}
	while (temp && temp->next != to_remove)
		temp = temp->next;
	if (temp)
	{
		temp->next = to_remove->next;
		free(to_remove->content);
		free(to_remove);
	}
}

/*This function checks every par in the list for a match with 
the cell par.*/
int	check_points(t_par *cell, t_list **points)
{
	t_list	*temp;
	t_par	*coor;

	temp = *points;
	while (temp)
	{
		coor = (t_par *)temp->content;
		if (coor->x == cell->x && coor->y == cell->y)
		{
			remove_cell(points, temp);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

/*This function checks to see if there is a path from
the starting point (start) to the end point (end) in the
given matrix. It creates a queue and adds the start point
to it. It then iterates through the queue, marking off
each point it visits with an 'X' and adding any adjacent points
to the queue. If it reaches the end point,
it returns 1, otherwise it returns 0.*/
int	is_path(char **matrix, t_par *start, t_list **points)
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
		if (check_points(temp, points) && !(*points))
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

/*This function checks to see if there is a path from
the player to the exit and every collectible in the
given map.*/
int	is_path_ultimate(t_map *map)
{
	ft_lstadd_back(&map->coll, ft_lstnew(newpar(map->exit->x, map->exit->y)));
	return (is_path(map->layout, map->player, &map->coll));
}
