/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_ctr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:42:30 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 13:36:02 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	xpm_ctrl(t_map *map)
{
	int		i;

	i = 0;
	map->xpm = (char **)malloc(sizeof(char *) * 6);
	if (!map->xpm)
		error_map(map);
	map->fdxpm = 0;
	map->xpm[0] = PLAYER;
	map->xpm[1] = COLLECT;
	map->xpm[2] = EXIT;
	map->xpm[3] = WALL;
	map->xpm[4] = SPACE;
	while (map->fdxpm >= 0 && i != 5)
	{
		map->fdxpm = open(map->xpm[i], O_RDONLY);
		close(map->fdxpm);
		i++;
	}
	if (map->fdxpm < 0)
	{
		ft_printf("Error\nThere is no XPM FILE!\n");
		error_xpm(map);
	}
}
