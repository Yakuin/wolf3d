/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:13:36 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/15 18:43:24 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					expose_event(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->buf, 0, 0);
	return (1);
}

int					exit_event(t_env *e)
{
	if (e)
		exit(1);
	return (1);
}

void				rotation(int rot, t_env *e)
{
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	rotSpeed = (rot == 124 ? ROT_SPEED : -ROT_SPEED);
	oldDirX = e->player->dir.x;
	oldPlaneX = e->player->plane.x;
	e->player->dir.x = e->player->dir.x * cos(-rotSpeed) - e->player->dir.y * sin(-rotSpeed);
	e->player->dir.y = oldDirX * sin(-rotSpeed) + e->player->dir.y * cos(-rotSpeed);
	e->player->plane.x = e->player->plane.x * cos(-rotSpeed) - e->player->plane.y * sin(-rotSpeed);
	e->player->plane.y = oldPlaneX * sin(-rotSpeed) + e->player->plane.y * cos(-rotSpeed);
}
int					key_events_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 12)
		(e->ovl->ovl_switch ? e->ovl->ovl_switch-- : e->ovl->ovl_switch++);
	if (keycode == 13)
		(e->rain_switch ? e->rain_switch-- : e->rain_switch++);
	if (keycode == 14)
		(e->blend_switch ? e->blend_switch-- : e->blend_switch++);
    if (keycode == 123)
		e->key_status[0] = '1';
	if (keycode == 124)
		e->key_status[1] = '1';
	if (keycode == 126)
		e->key_status[2] = '1';
	if (keycode == 125)
		e->key_status[3] = '1';
	return (1);
}

int					key_events_release(int keycode, t_env *e)
{
	
    if (keycode == 123)
		e->key_status[0] = '0';
	if (keycode == 124)
		e->key_status[1] = '0';
	if (keycode == 126)
		e->key_status[2] = '0';
	if (keycode == 125)
		e->key_status[3] = '0';
	return (1);
}
