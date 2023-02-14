/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:48:41 by daumis            #+#    #+#             */
/*   Updated: 2023/02/05 10:09:57 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cellfill(t_map *mapclone, int y, int x, t_elts *elements)
{
	if ((mapclone->map[y][x] == '1') || (mapclone->map[y][x] == 'F'))
		return ;
	else
	{
		if (mapclone->map[y][x] == 'C')
			elements->clonecol--;
		if (mapclone->map[y][x] == 'E')
			elements->exit_io = 1;
		mapclone->map[y][x] = 'F';
		cellfill(mapclone, y + 1, x, elements);
		cellfill(mapclone, y - 1, x, elements);
		cellfill(mapclone, y, x + 1, elements);
		cellfill(mapclone, y, x - 1, elements);
	}
}

void	floodfill(t_map *mapclone, t_elts *elements)
{
	elements->clonecol = elements->ccount;
	cellfill(mapclone, mapclone->pposy, mapclone->pposx, elements);
}
