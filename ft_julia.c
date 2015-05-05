/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 16:59:46 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/05 08:14:51 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	ft_init_env_ju(t_benv be)
{
	t_env e;

	e.x1 = -1 ;
	e.x2 = 1 ;
	e.y1 = -1.2 ;
	e.y2 = 1.2;
	e.zoom =  (be.factor);
	e.ite_max = 128; 
	e.image_x = 800;//(e.x2 - e.x1) * e.zoom;
	e.image_y = 800;// (e.y2 - e.y1) * e.zoom;
	/* printf("%f, %f, %f, %f, %d, %d, %d, %d \n ",e.x1, e.x2, e.y1, e.y2, e.zoom, e.ite_max, e.image_x, e.image_y); */
	return (e);
}

void ft_draw_ju(t_benv *be)
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
			e.c_r = be->factorx1; // -0.6
			e.c_i = be->factorx2; // 0.27015;


			e.z_r = 1.5 * (e.x - 400) / (0.5 * e.zoom * 800 )+ be->movex;
			e.z_i =1.5 *  (e.y - 400) / (0.5 * e.zoom * 800 )+ be->movey;
			e.i = 0;
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
				be->data[(800 * e.y + e.x) * 4 + 1] = 0*(50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 2] = 0*(50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 3] = 0*(50 + e.i * 1.5);
			}
			else 
			{
				be->data[(800 * e.y + e.x) * 4 + 1] = (50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 2] = (50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 3] = (50 + e.i * 1.5);
			}
			e.y += 1;
		}
		e.x += 1;
	} 
}
