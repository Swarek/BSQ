/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:02:21 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/07 01:22:39 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// Includes
# include "libft.h"

// Defines
# define TRUE (int)1
# define FALSE (int)0

# define STACK_A 1
# define STACK_B 0

# define ROTATE 0
# define REVERSE_ROTATE 1
# define SWAP 1
# define PUSH 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

char	**get_map(char *path);
void	algo(char **map);
void	draw_the_square(char **map);

#endif