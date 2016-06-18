/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:11:57 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/18 19:47:18 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		reset_map(t_env *e)
{
	int	x;
	int y;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (e->blend_switch)
				draw_pixel(e->buf, x, y, 0x7777FF);
			else
				draw_pixel(e->buf, x, y, 0x777777);
		}
	}
	y--;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (e->blend_switch)
				draw_pixel(e->buf, x, y, hex_color(0, 200, 0));
			else
				draw_pixel(e->buf, x, y, hex_color(0, (y / 20.0), 0));
		}
	}
}

inline void		draw_pixel(char *buf, int x, int y, int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		x *= 4;
		y *= 4;
		buf[(x++) + (y * WIN_WIDTH)] = color;
		buf[(x++) + (y * WIN_WIDTH)] = color >> 8;
		buf[(x) + (y * WIN_WIDTH)] = color >> 16;
	}
}

static void		print_line(t_env *e, t_rayinfo *data, int x)
{
	int		lineheight;
	int		drawStart;
	int		drawEnd;
	t_rgb	color;
	double	blend;

	lineheight = WIN_HEIGHT / data->distance;
    drawStart = -lineheight / 2 + WIN_HEIGHT / 2;
    if (drawStart < 0)
    	drawStart = 0;
    drawEnd = lineheight / 2 + WIN_HEIGHT / 2;
    if (drawEnd >= WIN_HEIGHT)
    	drawEnd = WIN_HEIGHT - 1;
	color_select(&color, &data->side);
	blend = data->distance / 2;
	if (blend < 1 || e->blend_switch)
		blend = 1.0;
	while (drawStart != drawEnd)
	{
		if (settexture)
			draw_pixel(e->buf, x, drawStart, gettexture());
		else
			draw_pixel(e->buf, x, drawStart, hex_color(color.r / blend, color.g / blend, color.b / blend));
      	drawStart++;
	}
}

//char gauche droite haut bas
static void		check_keys(t_env *e)
{

	if(e->key_status[0] == '1')
		rotation(123, e);
	if(e->key_status[1] == '1')
		rotation(124, e);
	if(e->key_status[2] == '1')
	{
		if (collision_check(e, 0))
		{
			e->player->pos.x += e->player->dir.x / 2;
			e->player->pos.y += e->player->dir.y / 2;
		}
	}
	if(e->key_status[3] == '1')
	{
		if (collision_check(e, 1))
		{
			e->player->pos.x -= e->player->dir.x / 2;
			e->player->pos.y -= e->player->dir.y / 2;
		}
	}
}

int				print(t_env *e)
{
	int			x;
	t_rayinfo	*rayinfo;
	t_ray		*r;

	r = (t_ray*)malloc(sizeof(t_ray));
	rayinfo = (t_rayinfo*)malloc(sizeof(t_rayinfo));
	rayinfo->side = 0;
	rayinfo->distance = 0;
	x = -1;
	reset_map(e);
	check_keys(e);
	while (++x < WIN_WIDTH)
	{
		r->camerax = 2 * x / (double)WIN_WIDTH - 1;
		r->rayposx = e->player->pos.x;
		r->rayposy = e->player->pos.y;
		r->raydirx = e->player->dir.x + e->player->plane.x * r->camerax;
		r->raydiry = e->player->dir.y + e->player->plane.y * r->camerax;
		raycast(e, r, rayinfo);
		print_line(e, rayinfo, x);
	}
	print_crosshair(e);
	if (e->rain_switch == 1)
		print_rain(e);
	free(r);
	free(rayinfo);
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
	print_overlay(e);
	return (1);
}
