/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 08:10:56 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/08 17:52:16 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	ft_init_env_mandel(t_benv be)
{
	t_env e;

	e.x1 = -2.1 + be.factorx1;
	e.x2 = 0.6 - be.factorx2;
	e.y1 = -1.2 + be.factory1;
	e.y2 = 1.3 - be.factory2;
	e.zoom = (be.factor);
	e.ite_max = 75; 
	e.image_x = 800;
	e.image_y = 800;
	return (e);
}

int motion_hook_mand(int x, int y, t_benv *be)
{
	(void)x;
	(void)y;
	if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
		be->fil += be->f;
	else
		be->fil -= be->f;
	expose_hook_mandel(be);
	return(0);
}

void ft_draw_mandel(t_benv *be)
{
	t_env e;

	e = ft_init_env_mandel(*be);
	e.x = 0;
	e.y = 0;
	while (e.x < e.image_x)
	{
		e.y = 0;
		while (e.y < e.image_y)
		{
			e.c_r = 3 * (e.x - 800 / 2) /
				( be->factor * 800) + be->movex;
			e.c_i = 3 * (e.y - 800 / 2) /
				( be->factor * 800) + be->movey;
			e.z_r = 0;
			e.z_i = 0;
			e.i = 0;
			while ((e.z_r * e.z_r + e.z_i * e.z_i < 4 && e.i < e.ite_max) ||
																	e.i == 0)
			{
				e.tmp = e.z_r;
				e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
				e.z_i = 2 * e.z_i * e.tmp + e.c_i;
				e.i += 1;
			}
			be->data[e.y * be->size_line + 4 * e.x + 0] = be->b *
			mlx_get_color_value(be->mlx, e.i * (be->fil + FF) / e.ite_max);
			be->data[e.y * be->size_line + 4 * e.x + 1] = be->g *
			mlx_get_color_value(be->mlx, e.i * (be->fil + FF) / e.ite_max);
			be->data[e.y * be->size_line + 4 * e.x + 2] = be->r *
			mlx_get_color_value(be->mlx, e.i * (be->fil + FF) / e.ite_max);
			e.y += 1;
		}
		e.x += 1;
	} 
}
