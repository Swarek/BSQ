/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:07 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/07 01:23:15 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (ft_error_msg("Need only 1 arg"));
	map = get_map(argv[1]);
	print_map(map);
	ft_printf("\n\n\n");
	algo(map);
	print_map(map);
	ft_printf("\n\n\n");
	draw_the_square(map);
	print_map(map);
	safe_free_all_strings(&map);
}
