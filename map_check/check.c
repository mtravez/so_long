/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:08 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/08 13:13:45 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*This function returns how many chars c are in the
character matrix.*/
int	how_many_chars(char **matrix, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*This function duplicates a character matrix*/
char	**ft_matrdup(char **matrix)
{
	char	**dup;
	int		i;
	char	*altogether;
	char	*temp;

	i = 0;
	altogether = ft_strdup("");
	while (matrix[i])
	{
		temp = ft_strjoin(altogether, matrix[i]);
		if (matrix[i + 1])
		{
			free(altogether);
			altogether = ft_strjoin_gnl(temp, ft_strdup(" "));
		}
		i++;
	}
	dup = ft_split(temp, ' ');
	free(temp);
	free(altogether);
	return (dup);
}
