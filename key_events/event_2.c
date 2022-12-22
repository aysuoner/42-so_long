/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:19:26 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 18:05:28 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	code_2(t_map *x)
{
	if (x->collect_lines[x->py / 64][(x->px + 64) / 64] == 'C')
	{
		x->collect_lines[x->py / 64][(x->px + 64) / 64] = '0';
		mlx_put_image_to_window(x->mlx, x->win, x->imgs, x->px + 64, x->py);
		x->coins--;
	}
	mlx_put_image_to_window(x->mlx, x->win, x->imgp, x->px + 64, x->py);
	mlx_put_image_to_window(x->mlx, x->win, x->imgs, x->px, x->py);
	x->step++;
	ft_printf("%d\n", x->step);
}

void	event_2(t_map *x)
{
	if (x->collect_lines[x->py / 64][(x->px + 64) / 64] != 'E')
	{
		code_2(x);
		x->px += 64;
	}
	else if (x->coins == 0)
	{
		x->step++;
		ft_printf("%d\n", x->step);
		free_map_and_mlx(x);
	}
}
