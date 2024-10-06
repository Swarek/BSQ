/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:24:18 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/07 01:19:04 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	del_nl(char **map)
{
	int		i;
	int		len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n' && map[i + 1])
			map[i][len - 1] = '\0';
		i++;
	}
}

char	**get_map(char *path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map = ft_safe_malloc((i + 1) * sizeof(char *));
	close (fd);
	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	return (close (fd), map[i] = NULL, del_nl(map), map);
}

// a = en haut
// b = a gauche
// c = en haut a gauche
char	min(char a, char b, char c)
{
	if (a == 'o' || b == 'o' || c == 'o')
		return ('0');
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	algo(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((i == 0 || j == 0) && map[i][j] != 'o')
				map[i][j] = '1';
			else if (map[i][j] != 'o')
				map[i][j] = min(map[i - 1][j], map[i][j - 1],
						map[i - 1][j - 1]) + 1;
			j++;
		}
		j = 0;
		i++;
	}
}
