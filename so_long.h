/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:13:14 by dylan             #+#    #+#             */
/*   Updated: 2023/05/01 08:28:19 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "mlx_linux/mlx.h"

/*Map collection*/
typedef struct s_map
{
	char	**map;
	char	*name;
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

/*Image collection info storage*/
typedef struct s_image
{
	char	*plyr;
	char	*wl;
	char	*col;
	char	*floor;
	char	*exit0;
	char	*exit1;
	char	*texit;
	int		igh;
	int		igw;

}	t_image;

/*Misc Data collection*/
typedef struct s_data
{
	t_map		*map;
	t_map		*mapclone;
	t_elts		*elts;
	t_image		*ig;
	void		*mlx;
	void		*mlx_win;
	void		*imgp;
	void		*imgw;
	void		*imgc;
	void		*imge0;
	void		*imge1;
	void		*imgf;
	void		*imgte;
	int			plyr;
	int			wl;
	int			col;
	int			floor;
	int			keycode;
	int			ex0;
	int			ex1;
	int			ext;
	int			dx;
	int			dy;
	int			moves;

}	t_data;

/*Map Handler*/
char	*joinstr(char *s1, char *s2);
void	createmap(t_map *map);
void	clonevalues(t_map *map, t_map *mapclone);
void	getmap(t_map *map, char *argv);
void	getpositions(t_map *map);
void	initelts(t_map *map, t_map *mapcl, t_image *img, t_data *data);
void	cellfill(t_map *mapclone, int y, int x, t_elts *elements);
void	freeall(t_map *map, t_map *mapclone);
void	freemap(t_map *map);
void	freeelts(t_data *data);
int		countel(t_map *map, t_elts *elements);
/*Error handling*/
void	replace_bn(t_map *map);
void	floodfill(t_map *mapclone, t_elts *elements);
int		errhandle(t_map *map, t_elts	*elements);
int		checkrectangle(t_map *map);
int		checkinput(t_elts *elements, char c);
int		checkboundaries(t_map *map);
int		checksides(t_map *map);
int		isnotdoable(t_map *map, t_elts *elements);
int		checkargv(char *argv);
/*Map display*/
void	*display(t_map *map, t_data *data);
void	display2(char c, t_data *d);
void	display3(char c, t_data *d);
void	chargeimgs(t_data *data, t_image *imgs);
void	gameon(t_data *data, t_map *map, t_image *img, t_map *mapclone);
void	exitcase(t_data *game, int keycode);
void	exitcase2(t_data *game, int keycode);
int		gameoff(t_data *data);
/*Movements*/
int		key_hook(int keycode, t_data *game);
int		movleft(t_data *game, int keycode);
int		movright(t_data *game, int keycode);
int		movup(t_data *game, int keycode);
int		movdown(t_data *game, int keycode);

#endif