/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:48:41 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 08:28:34 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	isnotdoable(t_map *mapclone, t_elts *elements)
{
	floodfill(mapclone, elements);
	if (elements->exit_io && !(elements->clonecol))
	{
		elements->exit_io = 0;
		return (0);
	}
	if ((elements->clonecol) && !(elements->exit_io))
	{
		ft_printf("Error\n");
		ft_printf("Map can't be completed: Collectibles & Exit not reachable\n");
	}
	else if (!(elements->exit_io))
	{
		ft_printf("Error\n");
		ft_printf("Map can't be completed: Exit is not reachable\n");
	}
	else if ((elements->clonecol))
	{
		ft_printf("Error\n");
		ft_printf("Map can't be completed: Collectible(s) not reachable\n");
	}
	free(mapclone->name);
	return (1);
}
