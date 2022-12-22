/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_the_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:13:46 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 18:06:04 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	if_1(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->imgs, map->x, map->y);
	mlx_put_image_to_window(map->mlx, map->win, map->imgw, map->x, map->y);
	map->i++;
	map->x = map->x + 64;
}

void	if_e(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->imgs, map->x, map->y);
	mlx_put_image_to_window(map->mlx, map->win, map->imge, map->x, map->y);
	map->i++;
	map->x = map->x + 64;
}

void	if_p(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->imgs, map->x, map->y);
	mlx_put_image_to_window(map->mlx, map->win, map->imgp, map->x, map->y);
	map->px = map->x;
	map->py = map->y;
	map->i++;
	map->x = map->x + 64;
}

void	if_c(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->imgs, map->x, map->y);
	mlx_put_image_to_window(map->mlx, map->win, map->imgc, map->x, map->y);
	map->i++;
	map->x = map->x + 64;
}

void	if_zero(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->imgs, map->x, map->y);
	map->i++;
	map->x = map->x + 64;
}
