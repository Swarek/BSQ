/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:13:17 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/07 01:25:46 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_coord	find_biggest_square(char **map)
{
	int		i;
	int		j;
	t_coord	max;

	i = 0;
	j = 0;
	max = (t_coord){0, 0};
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] > map[max.y][max.x] && map[i][j] != 'o')
				max = (t_coord){j, i};
			j++;
		}
		i++;
		j = 0;
	}
	return (max);
}

void	clean_the_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'x' && map[i][j] != 'o')
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_the_square(char **map)
{
	int		value_max;
	int		i;
	int		j;
	t_coord	max;

	max = find_biggest_square(map);
	value_max = map[max.y][max.x] - '0';
	i = 0;
	while (i < value_max)
	{
		j = 0;
		while (j < value_max)
		{
			map[max.y - i][max.x - j] = 'x';
			j++;
		}
		i++;
	}
	clean_the_map(map);
}
