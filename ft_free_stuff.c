/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:56:26 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/15 14:46:52 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *content)
{
	if (content)
		free(content);
	content = NULL;
}


void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_list(t_list *head)
{
	t_list *temp;

	temp = head;
	while (temp != NULL)
	{
		free(temp->content);
		head = temp->next;
		free(temp);
		temp = head;
	}
}

void	free_list_col(t_list *head)
{
	t_list			*temp;
	t_collectible	*cont;

	temp = head;
	while (temp != NULL)
	{
		cont = (t_collectible *) temp->content;
		free(cont->coor);
		free(temp->content);
		head = temp->next;
		free(temp);
		temp = head;
	}
}
// void	ft_free_player(t_player *player)
// {
// 	if (player)
// 	{
// 		ft_free(player->collectibles);
// 		ft_free(player->image);
// 	}
// 	ft_free(player);
// }

// void	ft_free_collectible(t_collectible *col)
// {
// 	if (col)
// 	{
// 		ft_free(col->collected);
// 		ft_free_par(col->coor);
// 	}
// 	ft_free(col);
// }

void	ft_free_map(t_map *map)
{
	free_list_col(map->coll);
	free(map->exit);
	free(map->player);
	free_matrix(map->layout);
	// free(map->length);
	// free(map->width);
	free(map);
}