
#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_benv *be)
{
	/* printf("mouse : %d (%d:%d)\n",button, x, y); */
	if (button == 4)
	{
		be->factor *= 1.1;
	be->movex += ((double)x - (800 / 2)) * 0.00038 /
		be->factor;
	/* printf("movex / %f", be->movex); */
	be->movey += ((double)y - (800 / 2)) * 0.00038 /
		be->factor;
	/* printf("   movex / %f \n", be->movey); */
	}
	if (button == 5)
	{
		be->factor /= 1.1;
	be->movex -= ((double)x - (800 / 2)) * 0.00038 /
		(800 / 800) / be->factor;
	be->movey -= ((double)y - (800 / 2)) * 0.00038 /
		(800 / 800) / be->factor;
	}
	expose_hook(be);
	return (0);
}

int	key_hook(int keycode, t_benv *be)
{
	/* printf("key : %d \n",keycode);fflush(stdout); */
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
		be->factor *= 1.1;
	if (keycode == 65364)
		be->factor /= 1.1;
	if (keycode == 97)
		be->factorx1+=1;
	if (keycode == 122)
		be->factorx2+=1;
	if (keycode == 101)
		be->factory1+=1;
	if (keycode == 114)
		be->factory2+=1;
	if (keycode == 113)
		be->factorx1-=1;
	if (keycode == 115)
		be->factorx2-=1;
	if (keycode == 100)
		be->factory1-=1;
	if (keycode == 102)
		be->factory2-=1;
	expose_hook(be);
	return (0);
}

int coucou(t_benv be)
{
	ft_set_pixel(&be);
//	mlx_clear_window(be.mlx, be.win);
	mlx_put_image_to_window(be.mlx, be.win, be.img, 0, 0 );
	return (0);
}

int	expose_hook(t_benv *be)
{
	coucou(*be);
	return (0);
}

int	main(int ac, char **av)
{
	t_benv be;

	be.factor = 1;
	be.movex = 0;
	be.movey = 0;
	be.factorx1 = 0;
	be.factorx2 = 0;
	be.factory1 = 0;
	be.factory2 = 0;
	be.mlx = mlx_init();
	be.img = mlx_new_image(be.mlx, l_wind, w_wind);
	be.data = mlx_get_data_addr(be.img, &be.bpp, &be.size_line, &be.endian);
	printf("bpp : %d   lsz : %d    end : %d\n", be.bpp, be.size_line, be.endian);
	//ft_set_pixel(&be);
	be.win = mlx_new_window(be.mlx, l_wind, w_wind, "42"); 
	mlx_key_hook(be.win, key_hook, &be);
	mlx_mouse_hook(be.win, mouse_hook, &be);
	mlx_expose_hook(be.win, expose_hook, &be);
	mlx_loop(be.mlx);
	return (0);
}
