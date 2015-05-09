/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 07:59:49 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/08 17:52:21 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook_mandel(int button, int x, int y, t_benv *be)
{

	if (button == 4)
	{
		be->factor *= 1.1;
		be->movex += ((double)x - (800 / 2)) * (0.00038 /
				be->factor);
		be->movey += ((double)y - (800 / 2)) * 0.00038 /
			be->factor;
	}
	if (button == 5)
	{
		be->factor /= 1.1;
		be->movex -= ((double)x - (800 / 2)) * 0.00038 /
			(800 / 800) / be->factor;
		be->movey -= ((double)y - (800 / 2)) * 0.00038 /
			(800 / 800) / be->factor;
	}
	expose_hook_mandel(be);
	return (0);
}

int key_hook_mandel(int keycode, t_benv *be)
{
	printf("%d\n", keycode);fflush(stdout);
	if (keycode == 65307)// || keycode == 53)
		exit(0);
	if (keycode == 125 || keycode == 65364)
		be->movey -= 0.1 / be->factor;
	if (keycode == 124 || keycode == 65363)
		be->movex -= 0.1 / be->factor;
	if (keycode == 126 || keycode == 65362)
		be->movey += 0.1 / be->factor;
	if (keycode == 123 || keycode == 65361)
		be->movex += 0.1 / be->factor;
	ft_color(keycode, be);
	ft_fillr(keycode, be);
	ft_fillg(keycode, be);
	ft_fillb(keycode, be);
	expose_hook_mandel(be);
	return (0);
}

int call_mandel(t_benv be)
{
	ft_draw_mandel(&be);
	mlx_put_image_to_window(be.mlx, be.win, be.img, 0, 0 );
	return (0);
}

int expose_hook_mandel(t_benv *be)
{
	call_mandel(*be);
	return (0);
}

int main_mandel(t_benv be)
{
	be.mlx = mlx_init();
	be.img = mlx_new_image(be.mlx, l_wind, w_wind);
	be.data = mlx_get_data_addr(be.img, &be.bpp, &be.size_line, &be.endian);
	//printf("%d %d %d ",be.bpp, be.size_line, be.endian);
	be.win = mlx_new_window(be.mlx, l_wind, w_wind, "Mandelbrot");
	mlx_expose_hook(be.win, expose_hook_mandel, &be);
	mlx_hook(be.win, 6, (1L<<6), motion_hook_mand, &be);
	mlx_key_hook(be.win, key_hook_mandel, &be);
	mlx_mouse_hook(be.win, mouse_hook_mandel, &be);
	mlx_loop(be.mlx);
	return (0);
}
