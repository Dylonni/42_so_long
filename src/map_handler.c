/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:53:38 by dylan             #+#    #+#             */
/*   Updated: 2023/02/05 10:46:32 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clonemap(t_map *map)
{
	int		fd;
	int		y;

	y = 0;
	fd = open("../maps/default.ber", O_RDONLY);
	map->map = ft_calloc(sizeof(map->map), map->mh);
	if (!map->map)
		return ;
	while (y < map->mh)
	{
		map->map[y] = get_next_line(fd);
		y++;
	}
	close(fd);
	y = 0;
	map->mw = ft_strlen(map->map[0]);
	while (y < map->mh)
	{
		map->map[y][map->mw - 1] = '\0';
		y++;
	}
	map->mw = ft_strlen(map->map[0]);
}

void	getmap(t_map *map)
{
	char	*line;
	int		fd;

	fd = open("../maps/default.ber", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		map->mh++;
		free(line);
	}
	map->mh -= 1;
	close(fd);
	clonemap(map);
}

int	countel(t_map *map, t_elts *elements)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->mh > y)
	{
		while (map->map[y][x])
		{
			if (!(checkinput(elements, map->map[y][x])))
				return (0);
			if (map->map[y][x] == 'C')
				elements->ccount++;
			if (map->map[y][x] == 'E')
				elements->ecount++;
			if (map->map[y][x] == 'P')
				elements->pcount++;
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	getpositions(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->mh > y)
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->pposx = x;
				map->pposy = y;
			}
			if (map->map[y][x] == 'E')
			{
				map->eposx = x;
				map->eposy = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
