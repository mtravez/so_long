/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:08 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/20 18:20:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	how_many_chars(char **matrix, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_collectible	*new_collectible(int x, int y)
{
	t_collectible	*newone;

	newone = malloc(sizeof(t_collectible *));
	if (!newone)
		return (NULL);
	newone->coor = newpar(x, y);
	newone->collected = 0;
	return (newone);
}

t_list	*get_collectibles(char **map)
{
	int		i;
	int		j;
	t_list	*collect;
	t_collectible	*temp;

	collect = NULL;
	temp = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				temp = new_collectible(j, i);
				ft_lstadd_back(&collect, ft_lstnew(temp));
			}
			j++;
		}
		i++;
	}
	return (collect);
}

int	is_path_coll(t_map *map)
{
	t_list			*temp;
	t_collectible	*current;
	char			**layout;

	temp = map->coll;
	while (temp)
	{
		layout = ft_matrdup(map->layout);
		current = temp->content;
		if (!is_path(layout, map->player, current->coor))
			return (0);
		temp = temp->next;
		free(layout);
	}
	return (1);
}

char	**ft_matrdup(char **matrix)
{
	char	**dup;
	int		rows;
	int		columns;

	rows = 0;
	while (matrix[rows])
		rows++;
	columns = ft_strlen(matrix[0]);
	dup = malloc(columns * rows);
	if (!dup)
		return (NULL);
	rows = 0;
	while (matrix[rows])
	{
		dup[rows] = ft_strdup(matrix[rows]);
		rows++;
	}
	return (dup);
}
