/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rectanglr_ctrl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:15:48 by aoner             #+#    #+#             */
/*   Updated: 2022/07/01 19:10:35 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	row_ctrl(t_map *map)
{
	int		li;
	int		row_len1;
	int		row_len2;

	li = 0;
	while (li != map->count_lines - 1)
	{
		row_len1 = ft_strlen(map->collect_lines[li]);
		li++;
		if (li != map->count_lines - 1)
			row_len2 = ft_strlen(map->collect_lines[li]);
		else if (li == map->count_lines - 1)
			row_len2 = ft_strlen(map->collect_lines[li]) + 1;
		if (row_len1 == row_len2)
			;
		else
			return (1);
	}
	return (0);
}

void	map_rectanglr_ctrl(t_map *map)
{
	if (row_ctrl(map) == 1)
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		error_map(map);
	}
}
