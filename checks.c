/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:33:24 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/13 12:29:27 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// int direction
// 0 = DEVANT
// 1 = DERRIERE
int		collision_check(t_env *e, int direction)
{
	t_ray r;
	t_rayinfo rayinfo;

	r.rayposx = e->player->pos.x;
	r.rayposy = e->player->pos.y;

	if (direction == 0)
	{
		r.raydirx = e->player->dir.x;
		r.raydiry = e->player->dir.y;
	}
	else
	{
		r.raydirx = -e->player->dir.x;
		r.raydiry = -e->player->dir.y;
	}
	raycast(e, &r, &rayinfo);
	
	if (rayinfo.distance > 1)
		return (1);
	else
		return (0);
}
