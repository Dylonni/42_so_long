/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:21:03 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 08:28:25 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*display(t_map *m, t_data *d)
{
	while (d->dy < m->mh)
	{
		while (m->map[d->dy][d->dx])
		{
			if (m->map[d->dy][d->dx] == '1')
				d->wl = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imgw,
						d->dx * d->ig->igw, d->dy * d->ig->igh);
			else if (m->map[d->dy][d->dx] == 'P')
				display2(m->map[d->dy][d->dx], d);
			else if (m->map[d->dy][d->dx] == '0')
				display2(m->map[d->dy][d->dx], d);
			else if (m->map[d->dy][d->dx] == 'C')
				display3(m->map[d->dy][d->dx], d);
			else if (m->map[d->dy][d->dx] == 'E')
				display3(m->map[d->dy][d->dx], d);
			else if (m->map[d->dy][d->dx] == 'T')
				display3(m->map[d->dy][d->dx], d);
			d->dx++;
		}
		d->dx = 0;
		d->dy++;
	}
	return (d->dx = 0, d->dy = 0, NULL);
}

void	display2(char c, t_data *d)
{
	if (c == 'P')
		d->plyr = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imgp,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
	if (c == '0')
		d->floor = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imgf,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
}

void	display3(char c, t_data *d)
{
	if (c == 'C')
		d->col = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imgc,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
	if (c == 'E' && !(d->elts->ccount))
		d->ex1 = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imge1,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
	else if (c == 'E')
		d->ex0 = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imge0,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
	if (c == 'T')
		d->ext = mlx_put_image_to_window(d->mlx, d->mlx_win, d->imgte,
				d->dx * d->ig->igw, d->dy * d->ig->igh);
}

void	chargeimgs(t_data *data, t_image *imgs)
{
	data->imgp = mlx_xpm_file_to_image(data->mlx, imgs->plyr, &imgs->igw,
			&imgs->igh);
	data->imge1 = mlx_xpm_file_to_image(data->mlx, imgs->exit1, &imgs->igw,
			&imgs->igh);
	data->imge0 = mlx_xpm_file_to_image(data->mlx, imgs->exit0, &imgs->igw,
			&imgs->igh);
	data->imgc = mlx_xpm_file_to_image(data->mlx, imgs->col, &imgs->igw,
			&imgs->igh);
	data->imgw = mlx_xpm_file_to_image(data->mlx, imgs->wl, &imgs->igw,
			&imgs->igh);
	data->imgf = mlx_xpm_file_to_image(data->mlx, imgs->floor, &imgs->igw,
			&imgs->igh);
	data->imgte = mlx_xpm_file_to_image(data->mlx, imgs->texit, &imgs->igw,
			&imgs->igh);
	if (!(data->imgp) || !(data->imge1) || !(data->imge0) || !(data->imgc)
		|| !(data->imgw) || !(data->imgf) || !(data->imgte))
	{
		ft_printf("Error\n Some images couldn't charge correctly");
		gameoff(data);
	}
}
