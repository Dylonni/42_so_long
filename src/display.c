/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:21:03 by daumis            #+#    #+#             */
/*   Updated: 2023/02/14 11:57:18 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display2(char c, t_image *ig, t_data *d)
{
	if (c == 'P')
	{
		d->ig = mlx_xpm_file_to_image(d->mlx, ig->plyr, &ig->igw,
				&ig->igh);
		d->plyr = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
				d->dx * 64, d->dy * 64);
	}
	if (c == '0')
	{
		d->ig = mlx_xpm_file_to_image(d->mlx, ig->floor, &ig->igw,
				&ig->igh);
		d->floor = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
				d->dx * 64, d->dy * 64);
	}
}

void	display3(char c, t_image *ig, t_data *d)
{
	if (c == 'C')
	{
		d->ig = mlx_xpm_file_to_image(d->mlx, ig->col, &ig->igw,
				&ig->igh);
		d->col = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
				d->dx * 64, d->dy * 64);
	}
	if (c == 'E')
	{
		d->ig = mlx_xpm_file_to_image(d->mlx, ig->exit0, &ig->igw,
				&ig->igh);
		d->ex0 = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
				d->dx * 64, d->dy * 64);
	}
	else if (c == 'E' && (d->elts->exit_io && !(d->elts->ccount)))
	{
		d->ig = mlx_xpm_file_to_image(d->mlx, ig->exit1, &ig->igw,
				&ig->igh);
		d->ex1 = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
				d->dx * 64, d->dy * 64);
	}
}

void	display(t_image *ig, t_map *m, t_data *d)
{
	printf("-----------\nDisplayed image ptr %p\n", ig);
	printf("Displayed map ptr %p\n", m);
	printf("Displayed data ptr %p\n", d);
	while (d->dy < m->mh)
	{
		while (m->map[d->dy][d->dx])
		{
			if (m->map[d->dy][d->dx] == '1')
			{
				d->ig = mlx_xpm_file_to_image(d->mlx, ig->wl, &ig->igw,
						&ig->igh);
				d->wl = mlx_put_image_to_window(d->mlx, d->mlx_win, d->ig,
						d->dx * 64, d->dy * 64);
			}
			else if (m->map[d->dy][d->dx] == 'P')
				display2(m->map[d->dy][d->dx], ig, d);
			else if (m->map[d->dy][d->dx] == '0')
				display2(m->map[d->dy][d->dx], ig, d);
			else if (m->map[d->dy][d->dx] == 'C')
				display3(m->map[d->dy][d->dx], ig, d);
			else if (m->map[d->dy][d->dx] == 'E')
				display3(m->map[d->dy][d->dx], ig, d);
			d->dx++;
		}
		d->dx = 0;
		d->dy++;
	}
}

void	gameon(t_data *data, t_map *map, t_image *img)
{
	int	c1;
	int	c2;

	c1 = 64 * map->mw;
	c2 = 64 * map->mh;
	data->map = map;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, c1, c2, "so_long");
	display(img, map, data);
	data->ig = img;
	if (!(mlx_key_hook(data->mlx_win, key_hook, data)))
	{
		movleft(data);
		display(data->ig, map, data);
	}
	mlx_hook(data->mlx_win, 17, 1L << 0, gameoff, data);
	mlx_loop(data->mlx);
}
