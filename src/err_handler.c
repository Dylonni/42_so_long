/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:10:22 by daumis            #+#    #+#             */
/*   Updated: 2023/02/05 10:47:10 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (c == 'C' || c == 'E' || c == 'P')
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

int	isnotdoable(t_map *mapclone, t_elts *elements)
{
	floodfill(mapclone, elements);
	if (elements->exit_io && !(elements->clonecol))
	{
		printf("Map is playable !\n");
		elements->exit_io = 0;
		return (0);
	}
	if ((elements->clonecol) && !(elements->exit_io))
		printf ("Map cannot be completed: Collectibles & Exit not reachable\n");
	else if (!(elements->exit_io))
		printf ("Map cannot be completed: Exit is not reachable\n");
	else if ((elements->clonecol))
		printf ("Map cannot be completed: Collectible(s) not reachable\n");
	return (1);
}
