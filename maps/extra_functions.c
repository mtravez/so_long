/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:39:41 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/20 20:25:59 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
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

void	get_exit_player(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->layout[i])
	{
		j = 0;
		while ((*map)->layout[i][j])
		{
			if ((*map)->layout[i][j] == 'P')
				(*map)->player = newpar(j, i);
			if ((*map)->layout[i][j] == 'E')
				(*map)->exit = newpar(j, i);
			j++;
		}
		i++;
	}
}

int	analize_chars(char **matrix, char *chars)
{
	int	i;
	int	j;
	int	k;
	int	correct;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			k = 0;
			correct = 0;
			while (!correct)
			{
				if (matrix[i][j] == chars[k])
					correct = 1;
				else
					k++;
				if (!chars[k])
				{
					return (0);
				}
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
	{
		ft_printf("extra char\n");
		return (0);
	}
	if (how_many_chars(map->layout, 'E') != 1)
	{
		ft_printf("wrong number of exits\n");
		return (0);
	}
	if (how_many_chars(map->layout, 'P')!= 1)
	{
		ft_printf("wrong number of player\n");
		return (0);
	}
	if (!how_many_chars(map->layout, 'C'))
	{
		ft_printf("not enough collectibles\n");
		return (0);
	}
	return (1);
}

/*TODO delete this before final*/
void	print_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			ft_printf("%c ", matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

/*TODO delete this before final*/
void	printlist(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		ft_printf("[%i, %i] -> ", ((int *)(temp->content))[0], ((int *)(temp->content))[1]);
		temp = temp->next;
	}
	ft_printf("\n");
}
