
#include "fractol.h"

t_env	ft_init_env(t_benv be)
{
	t_env e;

	/* printf("factor = %f\n", be.factor);fflush(stdout); */
	e.x1 = -2.1 + be.factorx1;// - be.factor;
	e.x2 = 0.6 - be.factorx2;// + be.factor;
	e.y1 = -1.2 + be.factory1;// - be.factor;
	e.y2 = 1.3 - be.factory2;//+ be.factor;
	e.zoom = (be.factor);
	e.ite_max = 300; 
	e.image_x = 800;//(e.x2 - e.x1) * e.zoom;
	e.image_y = 800;// (e.y2 - e.y1) * e.zoom;
	/* printf("%f, %f, %f, %f, %d, %d, %d, %d \n ",e.x1, e.x2, e.y1, e.y2, e.zoom, e.ite_max, e.image_x, e.image_y); */
	return (e);
}

void ft_set_pixel(t_benv *be)
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
			e.c_r = 2 * (e.x - 800 / 2) /
				(0.5 * be->factor * 800) + be->movex;
			e.c_i = 2 * (e.y - 800 / 2) /
				(0.5 * be->factor * 800) + be->movey;
			e.z_r = 0;
			e.z_i = 0;
			e.i = 0;
			while ((e.z_r * e.z_r + e.z_i * e.z_i < 4 && e.i <
							e.ite_max) || e.i == 0)
			{
				e.tmp = e.z_r;
				e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
				e.z_i = 2 * e.z_i * e.tmp + e.c_i;
				e.i += 1;
			}
				be->data[(800 * e.y + e.x) * 4 + 1] = (50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 2] = 0 *(50 + e.i * 1.5);
				be->data[(800 * e.y + e.x) * 4 + 3] = (50 + e.i * 1.5);
			e.y += 1;
		}
		e.x += 1;
	} 
}
