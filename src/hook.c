/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:21 by daumis            #+#    #+#             */
/*   Updated: 2023/02/14 11:11:47 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 119)
	{
		movup(game);
		displaymap(game->map);
	}
	if (keycode == 97)
	{
		movleft(game);
		displaymap(game->map);
	}
	if (keycode == 115)
	{
		movdown(game);
		displaymap(game->map);
	}
	if (keycode == 100)
	{
		movright(game);
		displaymap(game->map);
	}
	if (keycode == 65307)
		gameoff(game);
	return (0);
}

void	displaymap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->mh)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}
