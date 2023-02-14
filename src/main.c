/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:15 by dylan             #+#    #+#             */
/*   Updated: 2023/02/14 10:42:20 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_map *map, t_map *mapclone)
{
	int	i;

	i = 0;
	while (i < map->mh)
	{
		free(map->map[i]);
		free(mapclone->map[i]);
		i++;
	}
	free(map->map);
	free(mapclone->map);
	return ;
}

int	errhandle(t_map *map, t_elts	*elements)
{
	if (map->map[map->mh - 1] == NULL)
		return (printf("Error\nLine returns after end of map"));
	if (!(countel(map, elements)))
		return (printf("Error\nInvalid map inputs"));
	if (!(checkrectangle(map)))
		return (printf("Error\nThe map is not rectangular\n"));
	if (!(checkboundaries(map)) || !(checksides(map)))
		return (printf("Error\nMap is not well closed\n"));
	if (elements->bcount < 12)
		return (printf("Error\nMap is too small\n"));
	if (elements->ecount != 1)
		return (printf("Error\nThere should be 1 or only 1 exit\n"));
	if (elements->pcount != 1)
		return (printf("Error\nThere should be 1 or only 1 start position\n"));
	if (elements->ccount <= 0)
		return (printf("Error\nThere should at least 1 collectible\n"));
	return (0);
}

void	initelts(t_map *map, t_map *mapcl, t_image *img, t_data *data)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(mapcl, 0, sizeof(t_map));
	ft_memset(img, 0, sizeof(t_image));
	ft_memset(data, 0, sizeof(t_data));
	img->igh = 32;
	img->igw = 32;
	img->plyr = "../img/amogus_p.xpm";
	img->col = "../img/amogus_c.xpm";
	img->exit0 = "../img/vent_0.xpm";
	img->exit1 = "../img/vent_1.xpm";
	img->wl = "../img/amogus_box.xpm";
	img->floor = "../img/floor.xpm";
}

void	clonevalues(t_map *map, t_map *mapclone)
{
	mapclone->pposx = map->pposx;
	mapclone->pposy = map->pposy;
	mapclone->eposx = map->eposx;
	mapclone->eposy = map->eposy;
	mapclone->mh = map->mh;
	mapclone->mw = map->mw;
}

int	main(void)
{
	t_elts		elts;
	t_map		map;
	t_map		mapclone;
	t_image		img;
	t_data		data;

	ft_memset(&elts, 0, sizeof(t_elts));
	initelts(&map, &mapclone, &img, &data);
	getmap(&map);
	if ((errhandle(&map, &elts)))
		return (1);
	getmap(&mapclone);
	getpositions(&map);
	clonevalues(&map, &mapclone);
	if (isnotdoable(&mapclone, &elts))
		return (freeall(&map, &mapclone), 1);
	data.elts = &elts;
	gameon(&data, &map, &img);
	return (freeall(&map, &mapclone), 1);
}
