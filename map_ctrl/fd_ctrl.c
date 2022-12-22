/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:40:33 by aoner             #+#    #+#             */
/*   Updated: 2022/07/04 10:20:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	fd_ctrl(char *path, t_map *map)
{
	map->fd = open(path, O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("Error\nThere is no map with the requested name!");
		free(map);
		close(map->fd);
		exit(1);
	}
}
