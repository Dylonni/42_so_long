/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:15 by dylan             #+#    #+#             */
/*   Updated: 2023/05/01 10:49:28 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initelts(t_map *map, t_map *mapcl, t_image *img, t_data *data)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(mapcl, 0, sizeof(t_map));
	ft_memset(img, 0, sizeof(t_image));
	ft_memset(data, 0, sizeof(t_data));
	img->plyr = "img/amogus_p.xpm";
	img->col = "img/amogus_c.xpm";
	img->exit0 = "img/vent_0.xpm";
	img->exit1 = "img/vent_1.xpm";
	img->wl = "img/amogus_box.xpm";
	img->floor = "img/floor.xpm";
	img->texit = "img/amogus_te.xpm";
}

void	replace_bn(t_map *map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i <= map->mh)
	{
		if (ft_strchr(map->map[i], '\n'))
		{
			while (map->map[i][x] != '\n')
				x++;
			map->map[i][x] = '\0';
		}
		x = 0;
		i++;
	}
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

int	checkargv(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len - 3] == 'b'
		&& argv[len - 2] == 'e' && argv[len - 1] == 'r')
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_elts		elts;
	t_map		map;
	t_map		mapclone;
	t_image		img;
	t_data		data;

	if (argc != 2)
		return (1);
	if (!checkargv(argv[1]))
		return (1);
	ft_memset(&elts, 0, sizeof(t_elts));
	initelts(&map, &mapclone, &img, &data);
	getmap(&map, argv[1]);
	if ((errhandle(&map, &elts)))
		return (freemap(&map), 1);
	getmap(&mapclone, argv[1]);
	getpositions(&map);
	clonevalues(&map, &mapclone);
	if (isnotdoable(&mapclone, &elts))
		return (freeall(&map, &mapclone), free(map.name), 1);
	data.elts = &elts;
	elts.exit_io = 1;
	gameon(&data, &map, &img, &mapclone);
	return (0);
}
