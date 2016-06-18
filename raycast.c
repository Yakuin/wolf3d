/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:43:14 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/13 11:22:54 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		dda_algorithm(t_env *e, t_dda *dda, t_ray *r)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += dda->deltadistx;
			dda->mapx += dda->stepx;
			dda->side = (dda->stepx < 0 ? 1 : 3);
		}
		else
		{
			dda->sidedisty += dda->deltadisty;
			dda->mapy += dda->stepy;
			dda->side = (dda->stepy > 0 ? 2 : 4);
		}
		if (e->map[dda->mapx][dda->mapy] != '0')
			hit = 1;
	}
	dda->dist = ((dda->side == 1 || dda->side == 3) ?
				(dda->mapx - r->rayposx + (1 - dda->stepx) / 2)
				/ r->raydirx :
				(dda->mapy - r->rayposy + (1 - dda->stepy) / 2)
				/ r->raydiry);
}

void		get_step_sidedist(t_dda *dda, t_ray *r)
{
	if (r->raydirx < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (r->rayposx - dda->mapx) * dda->deltadistx;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1.0 - r->rayposx) * dda->deltadistx;
	}
	if (r->raydiry < 0)
	{
		dda->stepy = -1;
		dda->sidedisty = (r->rayposy - dda->mapy) * dda->deltadisty;
	}
	else
	{
		dda->stepy = 1;
		dda->sidedisty = (dda->mapy + 1.0 - r->rayposy) * dda->deltadisty;
	}
}

void		raycast(t_env *e, t_ray *r, t_rayinfo *rayinfo)
{
	t_dda dda;

	dda.mapx = (int)e->player->pos.x;
	dda.mapy = (int)e->player->pos.y;
	dda.deltadistx = sqrt(1 + (r->raydiry * r->raydiry)
						/ (r->raydirx * r->raydirx));
	dda.deltadisty = sqrt(1 + (r->raydirx * r->raydirx)
						/ (r->raydiry * r->raydiry));
	get_step_sidedist(&dda, r);
	dda_algorithm(e, &dda, r);
	rayinfo->distance = dda.dist;
	rayinfo->side = dda.side;
}
