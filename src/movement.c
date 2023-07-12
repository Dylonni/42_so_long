/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:41:07 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 08:28:56 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movup(t_data *game, int keycode)
{
	if (game->map->map[game->map->pposy - 1][game->map->pposx] == '1')
		return (0);
	if (game->map->map[game->map->pposy - 1][game->map->pposx] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
	{
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		gameoff(game);
	}
	else if (game->map->map[game->map->pposy - 1][game->map->pposx] == 'E')
		exitcase(game, keycode);
	else
	{
		if (game->map->map[game->map->pposy - 1][game->map->pposx] == 'C')
			game->elts->ccount--;
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy--;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->map, game);
		game->map->map[game->map->eposy][game->map->eposx] = 'E';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		display(game->map, game);
	}
	return (0);
}

int	movleft(t_data *game, int keycode)
{
	if (game->map->map[game->map->pposy][game->map->pposx - 1] == '1')
		return (0);
	if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
	{
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		gameoff(game);
	}
	else if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'E')
		exitcase2(game, keycode);
	else
	{
		if (game->map->map[game->map->pposy][game->map->pposx - 1] == 'C')
			game->elts->ccount--;
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx--;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->map, game);
		game->map->map[game->map->eposy][game->map->eposx] = 'E';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		display(game->map, game);
	}
	return (0);
}

int	movdown(t_data *game, int keycode)
{
	if (game->map->map[game->map->pposy + 1][game->map->pposx] == '1')
		return (0);
	if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
	{
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		gameoff(game);
	}
	else if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'E')
		exitcase(game, keycode);
	else
	{
		if (game->map->map[game->map->pposy + 1][game->map->pposx] == 'C')
			game->elts->ccount--;
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy++;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->map, game);
		game->map->map[game->map->eposy][game->map->eposx] = 'E';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		display(game->map, game);
	}
	return (0);
}

int	movright(t_data *game, int keycode)
{
	if (game->map->map[game->map->pposy][game->map->pposx + 1] == '1')
		return (0);
	if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'E'
				&& (game->elts->exit_io && !(game->elts->ccount)))
	{
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		gameoff(game);
	}
	else if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'E')
		exitcase2(game, keycode);
	else
	{
		if (game->map->map[game->map->pposy][game->map->pposx + 1] == 'C')
			game->elts->ccount--;
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx++;
		game->map->map[game->map->pposy][game->map->pposx] = 'P';
		display(game->map, game);
		game->map->map[game->map->eposy][game->map->eposx] = 'E';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		display(game->map, game);
	}
	return (0);
}

void	exitcase(t_data *game, int keycode)
{
	if (keycode == 119)
	{
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy--;
		game->map->map[game->map->pposy][game->map->pposx] = 'T';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
	}
	if (keycode == 115)
	{
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposy++;
		game->map->map[game->map->pposy][game->map->pposx] = 'T';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
	}
	display(game->map, game);
}
