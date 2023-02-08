/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:39:41 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/31 12:48:21 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include "map.h"

/*This function checks if every character in matrix is
also one of the characters in chars*/
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

/*This function checks that every character in the map is valid, 
that there isn't more than one exit, morre than one player, and at
least one collectible*/
int	check_chars(t_map *map)
{
	if (!analize_chars(map->layout, "01CPE"))
		return ((int)map_error("Error\nThere's an invalid char in map\n"));
	if (how_many_chars(map->layout, 'E') != 1)
		return ((int)map_error("Error\nWrong number of exits\n"));
	if (how_many_chars(map->layout, 'P') != 1)
		return ((int)map_error("Error\nWrong number of player\n"));
	if (!how_many_chars(map->layout, 'C'))
		return ((int)map_error("Error\nNot enough collectibles\n"));
	return (1);
}

/*This function frees the first chracter of a list, moves the head
of the list to the next cell, and returns the content of the freed
cell*/
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
