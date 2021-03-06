/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 16:59:46 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/09 17:56:38 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	ft_init_env_ju(t_benv be)
{
	t_env e;

	e.x1 = -1;
	e.x2 = 1;
	e.y1 = -1.2;
	e.y2 = 1.2;
	e.zoom = (be.factor);
	e.ite_max = 128;
	e.image_x = 800;
	e.image_y = 800;
	return (e);
}

void	ft_draw_ju(t_benv *be)
{
	t_env e;

	e = ft_init_env_ju(*be);
	e.x = 0;
	e.y = 0;
	while (e.x < e.image_x)
	{
		e.y = 0;
		while (e.y < e.image_y)
		{
			e.c_r = be->factorx1;
			e.c_i = be->factorx2;
			e.z_r = 1.5 * (e.x - 400) / (0.5 * e.zoom * 800) + be->movex;
			e.z_i = 1.5 * (e.y - 400) / (0.5 * e.zoom * 800) + be->movey;
			e.i = 0;
			e = ft_loop_ju(e, be);
			e.y += 1;
		}
		e.x += 1;
	}
}

t_env	ft_loop_ju(t_env e, t_benv *be)
{
	while ((e.z_r * e.z_r + e.z_i * e.z_i < 4 && e.i <
			e.ite_max) || e.i == 0)
	{
		e.tmp = e.z_r;
		e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
		e.z_i = 2 * e.z_i * e.tmp + e.c_i;
		e.i += 1;
	}
	if (e.i < e.ite_max)
	{
		be->data[(800 * e.y + e.x) * 4 + 1] = (50 + e.i * 1.5);
		be->data[(800 * e.y + e.x) * 4 + 2] = 0 * (50 + e.i * 1.5);
		be->data[(800 * e.y + e.x) * 4 + 3] = 0 * (50 + e.i * 1.5);
	}
	else
	{
		be->data[(800 * e.y + e.x) * 4 + 1] = be->r *
			(50 + e.i * 1.5);
		be->data[(800 * e.y + e.x) * 4 + 2] = be->g *
			(50 + e.i * 1.5);
		be->data[(800 * e.y + e.x) * 4 + 3] = be->b *
			(50 + e.i * 1.5);
	}
	return (e);
}

int		main_ju(t_benv be)
{
	be.mlx = mlx_init();
	be.img = mlx_new_image(be.mlx, L_WIND, W_WIND);
	be.data = mlx_get_data_addr(be.img, &be.bpp, &be.size_line, &be.endian);
	be.win = mlx_new_window(be.mlx, L_WIND, W_WIND, "Julia");
	mlx_expose_hook(be.win, expose_hook_ju, &be);
	mlx_hook(be.win, 6, (1L << 6), motion_hook, &be);
	mlx_key_hook(be.win, key_hook_ju, &be);
	mlx_mouse_hook(be.win, mouse_hook_ju, &be);
	mlx_loop(be.mlx);
	return (0);
}
