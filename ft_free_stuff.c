/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:56:26 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/20 15:58:00 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_list	*temp;

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
	if (map->coll)
		free_list_col(map->coll);
	if (map->exit != NULL)
		free(map->exit);
	if (map->player != NULL)
		free(map->player);
	if (map->layout)
		free_matrix(map->layout);
	if (map)
		free(map);
}

void	free_game(t_game *game)
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
	free(game);
}
