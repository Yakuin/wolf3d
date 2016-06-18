/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:43:58 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/10 10:39:04 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_overlay(t_env *e)
{
	if (e->ovl->ovl_switch)
	{
		mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF,
			ft_strjoin("dirx : ", ft_itoa(e->player->dir.x * 100)));
		mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
			ft_strjoin("diry : ", ft_itoa(e->player->dir.y * 100)));
		mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
			ft_strjoin("planex : ", ft_itoa(e->player->plane.x * 100)));
		mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF,
			ft_strjoin("planey : ", ft_itoa(e->player->plane.y * 100)));
		mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 370,
			10, 0xFFFFFF, "Use directional keys to move around");
		mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 130,
			30, 0xFFFFFF, "ESC to exit");
		mlx_string_put(e->mlx, e->win, WIN_HEIGHT - 280,
			50, 0xFFFFFF, "Press Q to hide/show infos");
	}
}
