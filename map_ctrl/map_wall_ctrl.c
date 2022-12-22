/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:25:01 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 17:56:11 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	map_linecount_ctrl(t_map *map)
{
	char	*nline;
	int		count;

	nline = get_next_line(map->fd);
	if (nline == NULL)
	{	
		ft_printf("Error\nThere are only NULL characters inside the map!");
		free(nline);
		free(map);
		close(map->fd);
		exit(1);
	}
	count = 0;
	while (nline != NULL)
	{
		free(nline);
		nline = get_next_line(map->fd);
		count++;
	}
	map->count_lines = count;
	return (count);
}

void	top_wall_ctrl(t_map *map, size_t li)
{
	size_t	i;

	i = 0;
	while (map->collect_lines[li][i])
	{	
		if (map->collect_lines[li][i] != '1' && i == 0)
		{
			ft_printf("Error\ntype1:Top wall check failed!\n");
			error_map(map);
		}
		if (map->collect_lines[li][i] != '1' \
		&& i != ft_strlen(map->collect_lines[li]) - 1)
		{
			ft_printf("Error\ntype2:Top wall check failed!\n");
			error_map(map);
		}
		i++;
	}
}

void	bot_wall_ctrl(t_map *map, size_t li)
{
	size_t	i;

	i = 0;
	while (map->collect_lines[li][i])
	{
		if (map->collect_lines[li][i] != '1')
		{
			ft_printf("Error\nBot wall check failed!\n");
			error_map(map);
		}
		i++;
	}
}

void	middle_walls_ctrl(t_map *map, size_t li)
{
	size_t	last_i;
	size_t	i;

	last_i = ft_strlen(map->collect_lines[li]) - 2;
	i = 0;
	if (map->collect_lines[li][i] == '1' \
	&& map->collect_lines[li][last_i] == '1')
		;
	else
	{
		ft_printf("Error\nMiddle wall check failed!\n\n");
		error_map(map);
	}
}

void	map_wall_ctrl(t_map *map)
{
	size_t	li;
	int		row;

	row = 0;
	while (row != map->count_lines)
	{
		li = row;
		if (row == 0)
		{
			top_wall_ctrl(map, li);
			row++;
		}
		else if (row != map->count_lines - 1)
		{
			middle_walls_ctrl(map, li);
			row++;
		}
		else if (row == map->count_lines - 1)
		{
			bot_wall_ctrl(map, li);
			row++;
		}
	}
}
