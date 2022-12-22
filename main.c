/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:44:28 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 18:41:32 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	save_map(char *path, t_map *map)
{
	size_t	k;

	k = 0;
	fd_ctrl(path, map);
	map->collect_lines = (char **)malloc(sizeof(char *) \
	* map_linecount_ctrl(map) + 1);
	if (!map->collect_lines)
	{
		free(map);
		close(map->fd);
		exit(1);
	}
	close(map->fd);
	map->fd = open(path, O_RDONLY);
	map->line = get_next_line(map->fd);
	while (map->line)
	{
		map->collect_lines[k++] = map->line;
		map->line = get_next_line(map->fd);
	}
	if (!map->line)
		map->collect_lines[k] = map->line;
	close(map->fd);
}

void	maintwo(t_map *map)
{
	map_wall_ctrl(map);
	map_rectanglr_ctrl(map);
	map_char_ctrl(map);
	map_difchar_ctrl(map);
	map->w = 0;
	map->h = 0;
	map->step = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, \
	(ft_strlen(map->collect_lines[0]) - 1) * 64, \
	map->count_lines * 64, "GOLD DIGGER COBRA MURAT");
	pinpointing_the_chars(map);
	mlx_hook(map->win, 2, 0, key_events, map);
	mlx_hook(map->win, 17, 0, close_x, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\nThe number of ARGC is not enough!");
		exit(1);
	}
	if (ft_rvstrncmp(argv[1], ".ber") != 0)
	{
		ft_printf("Error\nThe file named '.BER' was not found!");
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	save_map(argv[1], map);
	maintwo(map);
}
