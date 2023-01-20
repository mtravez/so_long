/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:45:04 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/20 16:04:13 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*This function creates a new tuple with the corresponding
variables as parameters
@param x the x integer of the pair
@param y the y integer of the pair*/
t_par	*newpar(int x, int y)
{
	t_par	*par;

	par = malloc(sizeof(t_par *));
	par->x = x;
	par->y = y;
	return (par);
}

/*This function creates a map from a file whose path is given
as parameter*/
t_map	*get_map(char *path)
{
	t_map	*map;
	char	**matrix;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	matrix = get_map_matrix(path);
	i = 0;
	while (matrix[i])
		i++;
	map->width = ft_strlen(matrix[0]);
	map->length = i;
	map->layout = ft_matrdup(matrix);
	get_exit_player(&map);
	map->coll = get_collectibles(matrix);
	free_matrix(matrix);
	if (is_correct(&map))
		return (map);
	else
	{
		ft_free_map(map);
		return (NULL);
	}
}

/*This function creates a collectible*/
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

/*This function creates a list of collectibles*/
t_list	*get_collectibles(char **map)
{
	int				i;
	int				j;
	t_list			*collect;
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

void	get_exit_player(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	(*map)->player = NULL;
	(*map)->exit = NULL;
	while ((*map)->layout[i])
	{
		j = 0;
		while ((*map)->layout[i][j])
		{
			if ((*map)->layout[i][j] == 'P' && !(*map)->player)
				(*map)->player = newpar(j, i);
			if ((*map)->layout[i][j] == 'E' && !(*map)->exit)
				(*map)->exit = newpar(j, i);
			j++;
		}
		i++;
	}
}
