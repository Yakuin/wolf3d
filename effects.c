/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 19:31:42 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/18 19:33:39 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			print_rain(t_env *e)
{
	int rain;
	int i;
	int x;
	int y;

	rain = -1;
	while (++rain < 60)
	{
		i = -1;
		x = random() % WIN_WIDTH - 1;
		y = random() % WIN_HEIGHT - 100;
		
		while (++i < 100 || y > WIN_HEIGHT || x > WIN_WIDTH)
		{
			draw_pixel(e->buf, x, y, hex_color(200, 200, 200));
			y++;
		}
	}	
}

void			print_crosshair(t_env *e)
{
	int 	y;
	int		x;

	y = (WIN_HEIGHT / 2) - 30;
	x = WIN_WIDTH / 2;
	while (y <= (WIN_HEIGHT / 2) + 30)
	{
		draw_pixel(e->buf, x - 1, y, 0x000000);
		draw_pixel(e->buf, x, y, 0x000000);
		draw_pixel(e->buf, x + 1, y, 0x000000);
		y++;
	}
	y = WIN_HEIGHT / 2;
	x = (WIN_WIDTH / 2) - 30;
	while (x <= (WIN_WIDTH / 2) + 30)
	{
		draw_pixel(e->buf, x, y - 1, 0x000000);
		draw_pixel(e->buf, x, y, 0x000000);
		draw_pixel(e->buf, x, y + 1, 0x000000);
		x++;
	}
}

