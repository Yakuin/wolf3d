/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:26:31 by yboualla          #+#    #+#             */
/*   Updated: 2016/06/15 18:43:42 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		err_handle(int errnum)
{
	if (errnum == 0)
		ft_putstr("Error : Malloc failed\n");
	else
		ft_putstr("Unknown error (too lazy to write a decent error message)");
	exit(0);
}

void		loadmap(char **map)
{
	map[0] = ft_strdup("111111111111111111");
	map[1] = ft_strdup("100000000000000001");
	map[2] = ft_strdup("100000000000000001");
	map[3] = ft_strdup("100000000000000001");
	map[4] = ft_strdup("100000200000000001");
	map[5] = ft_strdup("100000000000000001");
	map[6] = ft_strdup("100000000000000001");
	map[7] = ft_strdup("100000200000000001");
	map[8] = ft_strdup("100000000000000001");
	map[9] = ft_strdup("100000000000000001");
	map[10] = ft_strdup("100000000000000001");
	map[11] = ft_strdup("100020000000000001");
	map[12] = ft_strdup("100000000000000001");
	map[13] = ft_strdup("100000000002000001");
	map[14] = ft_strdup("100000000000000001");
	map[15] = ft_strdup("100000000000000001");
	map[16] = ft_strdup("100000000000000001");
	map[17] = ft_strdup("111111111111111111");
	map[18] = NULL;
}

void		player_init(t_player *player, float x, float y)
{
	player->pos.x = x;
	player->pos.y = y;
	player->dir.y = 0.64;
	player->dir.x = -0.76;
	player->plane.x = 0.42;
	player->plane.y = 0.50;
}

static void	env_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "YAMETE");
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		err_handle(0);
	e->img->data = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	if (!(e->ovl = (t_overlay *)malloc(sizeof(t_overlay))))
		err_handle(0);
	e->key_status[0] = '0';
	e->key_status[1] = '0';
	e->key_status[2] = '0';
	e->key_status[3] = '0';
	e->rain_switch = 1;
	e->blend_switch = 0;
	e->ovl->ovl_switch = 1;
	e->map = (char**)malloc(sizeof(char*) * 19);
	loadmap(e->map);
	e->player = (t_player*)malloc(sizeof(t_player));
	player_init(e->player, 10, 10);
}

int			main(void)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		err_handle(0);
	env_init(e);
	print(e);
	mlx_expose_hook(e->win, expose_event, e);
	mlx_mouse_hook(e->win, mouse_events, e);
	mlx_hook(e->win, 6, 1L << 6, motion_events, e);
	mlx_hook(e->win, 17, 1L << 17, exit_event, e);
	mlx_hook(e->win, 2, 1L << 0, key_events_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_events_release, e);
	mlx_loop_hook(e->mlx, print, e);
	mlx_loop(e->mlx);
	return (0);
}
