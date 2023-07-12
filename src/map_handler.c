/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:53:38 by dylan             #+#    #+#             */
/*   Updated: 2023/05/01 08:28:51 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	createmap(t_map *map)
{
	int		fd;
	int		y;

	y = 0;
	fd = open(map->name, O_RDONLY);
	map->map = malloc((map->mh + 1) * sizeof(map->map));
	if (!map->map)
		(ft_printf("Error\n Map allocation failed"), free(map->name), exit(1));
	while (y < map->mh)
	{
		map->map[y] = get_next_line(fd);
		y++;
	}
	map->map[y] = get_next_line(fd);
	close(fd);
	replace_bn(map);
	map->mw = ft_strlen(map->map[0]);
}

void	getmap(t_map *map, char *argv)
{
	char	*line;
	int		fd;

	map->name = joinstr("maps/", argv);
	fd = open(map->name, O_RDONLY);
	if (fd < 0)
	{
		free(map->name);
		exit (1);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		map->mh++;
		free(line);
	}
	close(fd);
	if (map->mh < 3)
	{
		free(map->name);
		exit (1);
	}
	map->mh -= 1;
	createmap(map);
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

char	*joinstr(char *s1, char *s2)
{
	char	*joined;
	size_t	lens1;
	size_t	lens2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!joined)
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
