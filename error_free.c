/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:22:42 by aoner             #+#    #+#             */
/*   Updated: 2022/07/04 10:16:49 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_map(t_map *map)
{
	size_t	li;

	li = 0;
	while (map->collect_lines[li])
	{
		free(map->collect_lines[li]);
		li++;
	}
	free(map->collect_lines);
	free(map);
	exit(1);
}

void	free_map_and_mlx(t_map *map)
{
	size_t	li;

	mlx_destroy_image(map->mlx, map->imgw);
	mlx_destroy_image(map->mlx, map->imge);
	mlx_destroy_image(map->mlx, map->imgp);
	mlx_destroy_image(map->mlx, map->imgc);
	mlx_destroy_image(map->mlx, map->imgs);
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	li = 0;
	while (map->collect_lines[li])
	{
		free(map->collect_lines[li]);
		li++;
	}
	free(map->collect_lines);
	free(map->xpm);
	free(map);
	exit(0);
}

void	error_xpm(t_map *map)
{
	size_t	li;

	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	li = 0;
	while (map->collect_lines[li])
	{
		free(map->collect_lines[li]);
		li++;
	}
	free(map->collect_lines);
	free(map->xpm);
	free(map);
	exit(1);
}
