/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinpointing_the_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:33:58 by buozdemi          #+#    #+#             */
/*   Updated: 2022/07/02 18:41:19 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	from_xpm_to_img(t_map *map)
{
	xpm_ctrl(map);
	map->imgw = mlx_xpm_file_to_image(map->mlx, WALL, &map->w, &map->h);
	map->imge = mlx_xpm_file_to_image(map->mlx, EXIT, &map->w, &map->h);
	map->imgp = mlx_xpm_file_to_image(map->mlx, PLAYER, &map->w, &map->h);
	map->imgc = mlx_xpm_file_to_image(map->mlx, COLLECT, &map->w, &map->h);
	map->imgs = mlx_xpm_file_to_image(map->mlx, SPACE, &map->w, &map->h);
}

void	if_newline(t_map *map)
{
	map->li++;
	map->y = map->y + 64;
	map->i = 0;
	map->x = 0;
}

void	pinpointing_the_chars(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->i = 0;
	map->li = 0;
	from_xpm_to_img(map);
	while (map->li != map->count_lines)
	{
		if (map->collect_lines[map->li][map->i] == '1')
			if_1(map);
		else if (map->collect_lines[map->li][map->i] == 'E')
			if_e(map);
		else if (map->collect_lines[map->li][map->i] == 'P')
			if_p(map);
		else if (map->collect_lines[map->li][map->i] == 'C')
			if_c(map);
		else if (map->collect_lines[map->li][map->i] == '0')
			if_zero(map);
		else if (map->collect_lines[map->li][map->i] == '\0' || \
		map->collect_lines[map->li][map->i] == '\n')
			if_newline(map);
	}
}
