/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:08:01 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/13 16:06:35 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hex_color(int r, int g, int b)
{
	int result;

//	if (r > 255)
//		r = 255;
//	if (g > 255)
//		g = 255;
//	if (b > 255)
//		b = 255;
//	if (r < 0)
//		r = 0;
//	if (g < 0)
//		g = 0;
//	if (b < 0)
//		b = 0;
	result = (r << 16) + (g << 8) + b;
//	result = r + g + b;
	return (result);
}

void	color_select(t_rgb *color, int *side)
{
	if (*side == 1)
	{
//		*color = 0x888800;
		color->r = 0x88;
		color->g = 0x88;
		color->b = 0;
	}
	if (*side == 2)
	{
//		*color = 0x00AA00;
		color->r = 0;
		color->g = 0xAA;
		color->b = 0;
	}
	if (*side == 3)
	{
//		*color = 0xCC00FF;
		color->r = 0xCC;
		color->g = 0;
		color->b = 0xFF;
	}
	if (*side == 4)
	{
//		*color = 0xDDDDD0;
		color->r = 0xDD;
		color->g = 0xDD;
		color->b = 0xD0;
	}
}
