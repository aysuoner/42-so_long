/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_difchar_ctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:58:25 by aoner             #+#    #+#             */
/*   Updated: 2022/07/01 19:10:12 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	difchar_ctrl(t_map *map)
{
	int		i;
	int		li;
	int		len;
	char	**a;

	li = 1;
	a = map->collect_lines;
	len = ft_strlen(map->collect_lines[li]);
	while (li != map->count_lines - 1)
	{
		i = 1;
		while (i != len - 2)
		{
			if (a[li][i] == '1' || a[li][i] == '0' || a[li][i] == 'P'\
			|| a[li][i] == 'C' || a[li][i] == 'E')
				i++;
			else
				return (1);
		}
		li++;
	}
	return (0);
}

void	map_difchar_ctrl(t_map *map)
{
	if (difchar_ctrl(map) == 1)
	{
		ft_printf("Error\nThe map contains UNWANTED CHARacters!\n");
		error_map(map);
	}
}
