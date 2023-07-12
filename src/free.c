/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:26:16 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 08:28:38 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freemap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->mh)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	freeelts(t_data *data)
{
	if (data->mlx)
	{
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->imgp)
			mlx_destroy_image(data->mlx, data->imgp);
		if (data->imgc)
			mlx_destroy_image(data->mlx, data->imgc);
		if (data->imge0)
			mlx_destroy_image(data->mlx, data->imge0);
		if (data->imge1)
			mlx_destroy_image(data->mlx, data->imge1);
		if (data->imgf)
			mlx_destroy_image(data->mlx, data->imgf);
		if (data->imgte)
			mlx_destroy_image(data->mlx, data->imgte);
		if (data->imgw)
			mlx_destroy_image(data->mlx, data->imgw);
	}
}

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
