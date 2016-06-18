/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:02:40 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/13 10:36:42 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					mouse_events(int button, int x, int y, t_env *e)
{
	x = 0;
	y = 0;
	if (button || x || y == 1)
		return (1);
	if (e)
		return (1);
	return (0);
}

int					motion_events(int x, int y, t_env *e)
{
	if (x || y == 1)
		return (1);
	if (e)
		return (1);
	return (0);
}
