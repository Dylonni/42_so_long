/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:21 by daumis            #+#    #+#             */
/*   Updated: 2023/05/01 08:28:42 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	gameon(t_data *data, t_map *map, t_image *img, t_map *mapclone)
{
	int	c1;
	int	c2;

	c1 = 64 * map->mw;
	c2 = 64 * map->mh;
	data->map = map;
	data->mapclone = mapclone;
	data->mlx = mlx_init();
	if (!(data->mlx))
		gameoff(data);
	data->ig = img;
	chargeimgs(data, img);
	data->mlx_win = mlx_new_window(data->mlx, c1, c2, "so_long");
	if (!data->mlx_win)
		gameoff(data);
	display(map, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, gameoff, data);
	mlx_loop(data->mlx);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 119)
		movup(game, keycode);
	if (keycode == 97)
		movleft(game, keycode);
	if (keycode == 115)
		movdown(game, keycode);
	if (keycode == 100)
		movright(game, keycode);
	if (keycode == 65307)
		gameoff(game);
	return (0);
}

void	exitcase2(t_data *game, int keycode)
{
	if (keycode == 97)
	{
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx--;
		game->map->map[game->map->pposy][game->map->pposx] = 'T';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
	}
	if (keycode == 100)
	{
		game->map->map[game->map->pposy][game->map->pposx] = '0';
		game->map->pposx++;
		game->map->map[game->map->pposy][game->map->pposx] = 'T';
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
	}
	display(game->map, game);
}

int	gameoff(t_data *data)
{
	if (data->map && data->mapclone)
		freeall(data->map, data->mapclone);
	if (data)
		freeelts(data);
	if (data->map->name)
		free(data->map->name);
	if (data->mapclone->name)
		free(data->mapclone->name);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (!(data->elts->ccount))
		ft_printf("Congratulations, you sussy BAKA !\n");
	exit (0);
}
