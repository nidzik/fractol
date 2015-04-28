
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
  e.ite_max = 150; 
  e.image_x = 800;//(e.x2 - e.x1) * e.zoom;
  e.image_y =800;// (e.y2 - e.y1) * e.zoom;
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
		putchar('c');
      while (e.y < e.image_y)
	{
		/* putchar('c'); */
		e.c_r = 1.5 * (e.x - 800 / 2) /
			(0.5 * be->factor * 800) + be->movex;
		e.c_i = 1.5 * (e.y - 800 / 2) /
			(0.5 * be->factor * 800) + be->movey;
	      /* e.c_r = (double)e.x / e.zoom + e.x1; */
	     /* e.c_i = (double)e.y / e.zoom + e.y1; */
	      e.z_r = 0;
	      e.z_i = 0;
	      e.i = 0;
	    while ((e.z_r * e.z_r + e.z_i * e.z_i < 4 && e.i < e.ite_max) || e.i == 0)
	    {
		/* putchar('b'); */
	      e.tmp = e.z_r;
	      e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
	      e.z_i = 2 * e.z_i * e.tmp + e.c_i;
	      e.i ++;
	    }
	    if (e.i == e.ite_max && (e.y * be->size_line + 4 * e.x) < (be->size_line * w_wind))
	      be->data[e.y * be->size_line + 4 * e.x] = mlx_get_color_value(be->mlx, 0xff0000);
	    else //if (e.i == e.ite_max  && (e.y * be->size_line + 4 * e.x) < (be->size_line * w_wind))
	      be->data[e.y * be->size_line + 4 * e.x] = mlx_get_color_value(be->mlx, 0x0000ff);
	    e.y++;
	}
      e.x++;
    } 
}
