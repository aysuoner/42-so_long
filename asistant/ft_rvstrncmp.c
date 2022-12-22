/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rvstrncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:19:03 by aoner             #+#    #+#             */
/*   Updated: 2022/06/30 14:19:08 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_rvstrncmp(const char *s1, const char *s2)
{
	int	i;
	int	k;
	int	m;

	i = ft_strlen(s1) - 1;
	m = ft_strlen(s1) - 1;
	k = ft_strlen(s2) - 1;
	while (i != m - 3 && (s1[i] && s2[k]) && (s1[i] == s2[k]))
	{	
		i--;
		k--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[k]);
}
