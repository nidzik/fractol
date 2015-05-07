/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_wtf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 07:59:49 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/07 15:14:36 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook_mandel_wtf(int button, int x, int y, t_benv *be)
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
	expose_hook_mandel_wtf(be);
	return (0);
}

int key_hook_mandel_wtf(int keycode, t_benv *be)
{
	printf("%d\n", keycode);fflush(stdout);
	if (keycode == 65307)
		exit(0);
	if (keycode == 'q')
		be->factorx1 += 0.1;
	if (keycode == 's')
		be->factorx2 += 0.01;
	if (keycode == 'w')
		be->factorx1 += 0.1;
	if (keycode == 'x')
		be->factorx2 += 0.01;
	if (keycode == 'a' || keycode == 65364)
		be->movey -= 0.1 / be->factor;
	if (keycode == 'z' || keycode == 65363)
		be->movex -= 0.1 / be->factor;
	if (keycode == 'e' || keycode == 65362)
		be->movey += 0.1 / be->factor;
	if (keycode == 'r' || keycode == 65361)
		be->movex += 0.1 / be->factor;
	if (keycode == 't')
		be->factor *= 1.1;
	if (keycode == 'y')
		be->factor /= 1.1;
	ft_color(keycode, be);
	expose_hook_mandel_wtf(be);
	return (0);
}

int call_mandel_wtf(t_benv be)
{
	mlx_clear_window(be.mlx, be.win);
	be.data = mlx_get_data_addr(be.img, &be.bpp, &be.size_line, &be.endian);
	ft_draw_mandel_wtf(&be);
	mlx_put_image_to_window(be.mlx, be.win, be.img, 0, 0 );
	return (0);
}

int expose_hook_mandel_wtf(t_benv *be)
{
	call_mandel_wtf(*be);
	return (0);
}

int main_mandel_wtf(t_benv be)
{
	be.mlx = mlx_init();
	be.img = mlx_new_image(be.mlx, l_wind, w_wind);
	be.data = mlx_get_data_addr(be.img, &be.bpp, &be.size_line, &be.endian);
	printf("%d %d %d ",be.bpp, be.size_line, be.endian);
	be.win = mlx_new_window(be.mlx, l_wind, w_wind, "Mandelbrot");
	mlx_expose_hook(be.win, expose_hook_mandel_wtf, &be);
	mlx_key_hook(be.win, key_hook_mandel_wtf, &be);
	mlx_mouse_hook(be.win, mouse_hook_mandel_wtf, &be);
	mlx_loop(be.mlx);
	return (0);
}