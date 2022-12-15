/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:58:05 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/15 19:18:50 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include "../libft/libft.h"

typedef struct s_map
{
	int	length;
	int width;
	t_list	*coll;
	int	exit[2];
	int player[2];
	char **layout;
}	t_map;

typedef struct s_collectible
{
	int	*coor;
	int collected;
}	t_collectible;

int		works(char *path);
int		is_path(char **matrix, int start[2], int end[2]);
int		is_path_coll(t_map *map);
int		how_many_chars(char **matrix, char c);
char	**ft_matrdup(char **matrix);

#endif