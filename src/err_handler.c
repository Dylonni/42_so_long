/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:10:22 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 10:58:07 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkinput(t_elts *elements, char c)
{
	if (c == '0')
	{
		elements->vcount++;
		return (1);
	}
	if (c == '1')
	{
		elements->bcount++;
		return (1);
	}
	else if (c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

int	checkrectangle(t_map *map)
{
	int		y;
	int		clmapheight;
	size_t	checker;

	y = 0;
	clmapheight = map->mh;
	checker = map->mw;
	while (clmapheight)
	{
		if (ft_strlen(map->map[y]) != checker)
			return (0);
		y++;
		clmapheight--;
	}
	return (1);
}

int	checkboundaries(t_map *map)
{
	int	x;

	x = 0;
	while (map->map[0][x])
	{
		if (map->map[0][x] == '1')
			x++;
		else
			return (0);
	}
	x = 0;
	while (map->map[map->mh - 1][x])
	{
		if (map->map[map->mh - 1][x] == '1')
			x++;
		else
			return (0);
	}
	return (1);
}

int	checksides(t_map *map)
{
	int	y;

	y = 1;
	while (map->map[y] && y < (map->mh - 1))
	{
		if (map->map[y][0] == '1' && map->map[y][map->mw - 1] == '1')
			y++;
		else
			return (0);
	}
	return (1);
}

int	errhandle(t_map *map, t_elts	*elements)
{
	if (!(countel(map, elements)))
	{
		ft_printf("Error\nInvalid map inputs");
		return (free(map->name), 1);
	}
	if (!(checkrectangle(map)))
	{
		ft_printf("Error\nMap is not rectangular or has too much line returns\n");
		return (free(map->name), 1);
	}
	if (!(checkboundaries(map)) || !(checksides(map)))
	{
		ft_printf("Error\nMap is not well closed\n");
		return (free(map->name), 1);
	}
	if (elements->ecount != 1 || elements->pcount != 1 || elements->ccount <= 0)
	{
		ft_printf("Error\nThere must be 1Exit, 1Start & at least 1Collectible\n");
		return (free(map->name), 1);
	}
	return (0);
}
