/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opshit.cu                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:22:56 by nidzik            #+#    #+#             */
/*   Updated: 2015/04/29 11:35:38 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cuda.h>
#include <cuda_call.h>
#include <stdio.h>

extern "C" void ft_set_pixel(t_benv *be)
{
  t_env e;
  e = ft_init_env(*be);
  e.x = 0;
  e.y = 0;
  while (e.x < e.image_x)
    {
      e.y = 0;
      while (e.y < e.image_y)
	{
		e.c_r = 1.5 * (e.x - 400) /	(be->factor * 400) + be->movex;
		e.c_i = 1.5 * (e.y - 400) /	(be->factor * 400) + be->movey;
		e.z_r = 0;
		e.z_i = 0;
		e.i = 0;
	    while ((e.z_r * e.z_r + e.z_i * e.z_i < 4 && e.i < e.ite_max) || e.i == 0)
	    {
	      e.tmp = e.z_r;
	      e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
	      e.z_i = 2 * e.z_i * e.tmp + e.c_i;
	      e.i ++;
	    }
	    if (e.i == e.ite_max && (e.y * be->size_line + 4 * e.x) < (be->size_line * w_wind))
	      be->data[e.y * be->size_line + 4 * e.x] = mlx_get_color_value(be->mlx, 0xff0000);
	    else
	      be->data[e.y * be->size_line + 4 * e.x] = mlx_get_color_value(be->mlx, 0x0000ff);
	    e.y+=3;
	}
      e.x+=3;
    } 
  mlx_put_image_to_window(be->mlx, be->win, be->img, 0, 0);

}
