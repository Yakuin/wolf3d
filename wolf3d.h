/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:40:49 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/18 19:33:21 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include "libft/libft.h"
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define WIN_HEIGHT 1024
# define WIN_WIDTH 1024
# define WALL_SIZE 64
# define ROT_SPEED 0.05

typedef struct		s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_overlay
{
	int				ovl_switch;
}					t_overlay;

typedef struct		s_rayinfo
{
	float			distance;
	char			type;
	int				side;
}					t_rayinfo;

typedef struct		s_img
{
	void			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_player
{
	t_vector2		pos;
	t_vector2		dir;
	t_vector2		plane;
}					t_player;

typedef struct		s_dda
{
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			dist;
	int				stepx;
	int				stepy;
	int				side;
}					t_dda;

typedef struct		s_ray
{
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	char			*buf;
	t_overlay		*ovl;
	char			**map;
	t_player		*player;
	char			key_status[5];
	char			rain_switch;
	double			blend_switch;
}					t_env;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

void				draw_pixel(char *buf, int x, int y, int color);
int					expose_event(t_env *e);
int					mouse_events(int button, int x, int y, t_env *e);
int					motion_events(int x, int y, t_env *e);
int					key_events_press(int keycode, t_env *e);
int					key_events_release(int keycode, t_env *e);
void				rotation(int rot, t_env *e);
void				print_rain(t_env *e);
void				print_overlay(t_env *e);
int					print(t_env *e);
int					hex_color(int r, int g, int b);
void				color_select(t_rgb *color, int *side);
int					collision_check(t_env *e, int direction);
void				raycast(t_env *e, t_ray *r, t_rayinfo *rayinfo);
void				loadmap(char **map);
void				err_handle(int errnum);
int					exit_event(t_env *e);
void				print_crosshair(t_env *e)
#endif
