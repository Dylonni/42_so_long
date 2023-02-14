/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:13:14 by dylan             #+#    #+#             */
/*   Updated: 2023/02/14 11:05:24 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx_linux/mlx.h"

/*Map collection*/
typedef struct s_map
{
	char	**map;
	int		pposx;
	int		pposy;
	int		eposx;
	int		eposy;
	int		mh;
	int		mw;
}	t_map;

/*Map elements*/
typedef struct s_elts
{
	int	vcount;
	int	bcount;
	int	ccount;
	int	clonecol;
	int	ecount;
	int	pcount;
	int	exit_io;

}	t_elts;

/*Image collection*/
typedef struct s_image
{
	char	*plyr;
	char	*wl;
	char	*col;
	char	*floor;
	char	*exit0;
	char	*exit1;
	int		igh;
	int		igw;

}	t_image;

/*Data collection*/
typedef struct s_data
{
	t_map		*map;
	t_elts		*elts;
	t_image		*ig;
	int			plyr;
	int			wl;
	int			col;
	int			floor;
	int			keycode;
	int			ex0;
	int			ex1;
	int			dx;
	int			dy;
	void		*mlx;
	void		*mlx_win;
	void		*img;

}	t_data;

/*Map Handler*/
void	clonemap(t_map *map);
void	clonevalues(t_map *map, t_map *mapclone);
void	getmap(t_map *map);
void	getpositions(t_map *map);
void	initelts(t_map *map, t_map *mapcl, t_image *img, t_data *data);
void	cellfill(t_map *mapclone, int y, int x, t_elts *elements);
void	freeall(t_map *map, t_map *mapclone);
int		countel(t_map *map, t_elts *elements);
/*Error handling*/
void	floodfill(t_map *mapclone, t_elts *elements);
int		errhandle(t_map *map, t_elts	*elements);
int		checkrectangle(t_map *map);
int		checkinput(t_elts *elements, char c);
int		checkboundaries(t_map *map);
int		checksides(t_map *map);
int		isnotdoable(t_map *map, t_elts *elements);
/*Map display*/
int		gameoff(t_data *data);
void	gameon(t_data *data, t_map *map, t_image *img);
void	display(t_image *img, t_map *map, t_data *data);
void	display2(char c, t_image *ig, t_data *d);
void	display3(char c, t_image *ig, t_data *d);
void	displaymap(t_map *map);
/*Movements*/
int		key_hook(int keycode, t_data *game);
int		movleft(t_data *game);
int		movright(t_data *game);
int		movup(t_data *game);
int		movdown(t_data *game);

#endif