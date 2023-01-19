/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:56:26 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/19 15:50:27 by mtravez          ###   ########.fr       */
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

void free_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->exit[0]);
	mlx_delete_image(game->mlx, game->exit[1]);
	free(game->exit);
	mlx_delete_image(game->mlx, game->player->image[0]);
	mlx_delete_image(game->mlx, game->player->image[1]);
	mlx_delete_image(game->mlx, game->player->image[2]);
	mlx_delete_image(game->mlx, game->player->image[3]);
	free(game->player->image);
	free(game->player);
	mlx_delete_image(game->mlx, game->map_image[0]);
	mlx_delete_image(game->mlx, game->map_image[1]);
	mlx_delete_image(game->mlx, game->map_image[2]);
	mlx_delete_image(game->mlx, game->map_image[3]);
	mlx_delete_image(game->mlx, game->map_image[4]);
	free(game->map_image);
	ft_free_map(game->map);
	// mlx_terminate(game->mlx);
	free(game);
}
