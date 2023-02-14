/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:41:07 by daumis            #+#    #+#             */
/*   Updated: 2023/02/14 11:22:46 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movleft(t_data *game)
{
	if (game->map->map[game->map->pposy][game->map->pposx - 1] == '1')
		return (0);
	else if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'E')
		return (0);
	else if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
		gameoff(game);
	else
	{
		if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'C')
		{
			game->elts->ccount--;
			printf("%d\n", game->elts->ccount);
		}
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx -= 1;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		displaymap(game->map);
	}
	return (0);
}

int	movright(t_data *game)
{
	if (game->map->map[game->map->pposy][game->map->pposx + 1] == '1')
		return (0);
	else if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'E')
		return (0);
	else if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
		gameoff(game);
	else
	{
		if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'C')
		{
			game->elts->ccount--;
			printf("%d\n", game->elts->ccount);
		}
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx++;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->ig, game->map, game);
		displaymap(game->map);
	}
	return (0);
}

int	movup(t_data *game)
{
	if (game->map->map[game->map->pposy - 1][game->map->pposx] == '1')
		return (0);
	else if (game->map->map[game->map->pposy - 1][game->map->pposx - 1] == 'E')
		return (0);
	else if (game->map->map[game->map->pposy - 1][game->map->pposx] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
		gameoff(game);
	else
	{
		if (game->map->map[game->map->pposy - 1][game->map->pposx] == 'C')
		{
			game->elts->ccount--;
			printf("%d\n", game->elts->ccount);
		}
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy--;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->ig, game->map, game);
		displaymap(game->map);
	}
	return (0);
}

int	movdown(t_data *game)
{
	if (game->map->map[game->map->pposy + 1][game->map->pposx] == '1')
		return (0);
	else if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'E')
		return (0);
	else if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
		gameoff(game);
	else
	{
		if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'C')
		{
			game->elts->ccount--;
			printf("%d\n", game->elts->ccount);
		}
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy++;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->ig, game->map, game);
		displaymap(game->map);
	}
	return (0);
}

int	gameoff(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (1);
}
