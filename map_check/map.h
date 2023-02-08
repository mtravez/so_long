/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:58:05 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/08 13:15:43 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../lib/libft/libft.h"

typedef struct s_par
{
	int	x;
	int	y;
}	t_par;

typedef struct s_map
{
	int		length;
	int		width;
	int		coll_nr;
	t_list	*coll;
	t_par	*exit;
	t_par	*player;
	char	**layout;
}	t_map;

t_par	*newpar(int x, int y);
t_map	*get_map(char *path);
t_list	*get_collectibles(char **map);
void	get_exit_player(t_map **map);
char	**get_map_matrix(char *path);
int		is_path_ultimate(t_map *map);
int		how_many_chars(char **matrix, char c);
char	**ft_matrdup(char **matrix);
int		check_chars(t_map *map);

#endif