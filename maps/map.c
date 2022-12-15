/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:47 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/15 19:29:22 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

const int	g_directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

void	adjacent(char **matrix, const int cell[2], t_list **queue)
{
	int			i;
	int			a;
	int			b;
	int			rows;

	rows = 0;
	while (matrix[rows])
		rows++;
	i = 0;
	while (i < 4)
	{
		a = cell[0] + g_directions[i][0];
		b = cell[1] + g_directions[i][1];
		if (a >= 0 && b >= 0 && a < rows && b < ft_strlen(matrix[0])
			&& matrix[a][b] != 'X' && matrix[a][b] != '1')
		{
			int par[2] = {a, b};
			ft_lstadd_front(queue, ft_lstnew(par));
		}
		i++;
	}
}

int	is_path(char **matrix, int start[2], int end[2])
{
	t_list *queue;
	int		number[2];
	int		*temp;
	int		i;
	char	**layout;

	layout = ft_matrdup(matrix);
	queue = ft_lstnew(start);
	i = 0;
	while (queue)
	{
		i++;
		temp = (int *) queue->content;
		number[0] = temp[0];
		number[1] = temp[1];
		queue = queue->next;
		layout[temp[0]][temp[1]] = 'X';
		if (temp[0] == end[0] && temp[1] == end[1])
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
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				map->player[0] = i;
				map->player[1] = j;
			}
			if (matrix[i][j] == 'E')
			{
				map->exit[0] = i;
				map->exit[1] = j;
			}
			j++;;
		}
		i++;
	}
	if (!is_path(matrix, map->player, map->exit))
		perror("Error, invalid path");
	return (map);
}

int	works(char *path)
{
	char **matrix = get_map_matrix(path);
	t_map *map = is_correct(matrix);
	if (!map)
		return (0);
	int i = 0;
	while (matrix[i])
	{
		int j = 0;
		while (matrix[i][j])
		{
			ft_printf("%c ", matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (1);
}