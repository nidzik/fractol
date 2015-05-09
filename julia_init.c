/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 07:44:28 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/09 17:21:37 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook_ju(int button, int x, int y, t_benv *be)
{
	if (button == 4)
	{
		be->factor *= 1.1;
		be->movex += ((double)x - (800 / 2)) * (0.00038 /
				be->factor);
		be->movey += ((double)y - (800 / 2)) * 0.00038 /
			be->factor;
	}
	if (button == 5 || button == 7)
	{
		be->factor /= 1.1;
		be->movex -= ((double)x - (800 / 2)) * 0.00038 /
			(800 / 800) / be->factor;
		be->movey -= ((double)y - (800 / 2)) * 0.00038 /
			(800 / 800) / be->factor;
	}
	expose_hook_ju(be);
	return (0);
}

int motion_hook(int x, int y, t_benv *be)
{
	mlx_mouse_hook(be->win, mouse_hook_ju, be);
	if (be->stop == 0)
	{
		be->factorx1 = (double)x / 1250 - 1;
		be->factorx2 = (double)y / 450 - 1;
	}
	expose_hook_ju(be);
	return (0);
}

int key_hook_ju(int keycode, t_benv *be)
{
	if ((keycode == ' ' || keycode == 49) && be->stop == 1)
		be->stop = 0;
	else if (keycode == ' ' || keycode == 49)
		be->stop = 1;
	ft_color(keycode, be);
	expose_hook_ju(be);
	return (0);
}

int call_ju(t_benv be)
{
	ft_draw_ju(&be);
	mlx_put_image_to_window(be.mlx, be.win, be.img, 0, 0);
	return (0);
}

int expose_hook_ju(t_benv *be)
{
	call_ju(*be);
	return (0);
}
