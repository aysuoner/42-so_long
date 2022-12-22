/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:13:40 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 14:21:10 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	key_events(int keycode, t_map *x)
{	
	if (keycode == 13 && x->collect_lines[(x->py - 64) / 64][x->px / 64] != '1')
		event_13(x);
	else if (keycode == 1 && \
	x->collect_lines[(x->py + 64) / 64][x->px / 64] != '1')
		event_1(x);
	else if (keycode == 0 && \
	x->collect_lines[x->py / 64][(x->px - 64) / 64] != '1')
		event_zero(x);
	else if (keycode == 2 && \
	x->collect_lines[x->py / 64][(x->px + 64) / 64] != '1')
		event_2(x);
	else if (keycode == 53)
		free_map_and_mlx(x);
	return (0);
}
