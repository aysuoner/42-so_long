/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:01:10 by aoner             #+#    #+#             */
/*   Updated: 2022/07/04 10:19:49 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	char_e_ctrl(t_map *map)
{
	size_t	i;
	int		li;
	int		count;

	li = 1;
	count = 0;
	while (li != map->count_lines - 1)
	{	
		i = 1;
		while (map->collect_lines[li][i])
		{
			if (map->collect_lines[li][i] == 'E')
				count++;
			i++;
		}
		li++;
	}
	return (count);
}

int	char_p_ctrl(t_map *map)
{
	size_t	i;
	int		li;
	int		count;

	li = 1;
	count = 0;
	while (li != map->count_lines - 1)
	{	
		i = 1;
		while (map->collect_lines[li][i])
		{
			if (map->collect_lines[li][i] == 'P')
				count++;
			i++;
		}
		li++;
	}
	return (count);
}

int	char_zero_ctrl(t_map *map)
{
	size_t	i;
	int		li;
	int		count;

	li = 1;
	count = 0;
	while (li != map->count_lines - 1)
	{
		i = 1;
		while (map->collect_lines[li][i])
		{
			if (map->collect_lines[li][i] == '0')
				count++;
			i++;
		}
		li++;
	}
	return (count);
}

int	char_c_ctrl(t_map *map)
{
	size_t	i;
	int		li;
	int		coins;

	li = 1;
	coins = 0;
	while (li != map->count_lines - 1)
	{
		i = 1;
		while (map->collect_lines[li][i])
		{
			if (map->collect_lines[li][i] == 'C')
				coins++;
			i++;
		}
		li++;
	}
	map->coins = coins;
	return (coins);
}

void	map_char_ctrl(t_map *map)
{
	if (char_e_ctrl(map) == 0)
	{
		ft_printf("Error\nThere are not enough 'E' characters!\n");
		error_map(map);
	}
	else if (char_p_ctrl(map) != 1)
	{
		ft_printf("Error\nThere are not enough 'P' characters!\n");
		error_map(map);
	}
	else if (char_zero_ctrl(map) == 0)
	{	
		ft_printf("Error\nThere are not enough '0' characters!\n");
		error_map(map);
	}
	else if (char_c_ctrl(map) == 0)
	{
		ft_printf("Error\nThere are not enough 'C' characters!\n");
		error_map(map);
	}
}
