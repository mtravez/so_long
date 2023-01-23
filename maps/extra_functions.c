/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:39:41 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/22 21:12:13 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
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

int	analize_chars(char **matrix, char *chars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			k = 0;
			while (chars[k])
			{
				if (matrix[i][j] == chars[k])
					break ;
				if (!chars[k])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_chars(t_map *map)
{
	if (!analize_chars(map->layout, "01CPE"))
		return (map_error("Error\nThere's an invalid char in map\n"));
	if (how_many_chars(map->layout, 'E') != 1)
		return (map_error("Error\nWrong number of exits\n"));
	if (how_many_chars(map->layout, 'P') != 1)
		return (map_error("Error\nWrong number of player\n"));
	if (!how_many_chars(map->layout, 'C'))
		return (map_error("Error\nNot enough collectibles\n"));
	return (1);
}

void	*ft_lstpop(t_list **list)
{
	void	*content;
	t_list	*head;

	if (!list || !*list)
		return (NULL);
	head = *list;
	*list = (*list)->next;
	content = head->content;
	free(head);
	return (content);
}
