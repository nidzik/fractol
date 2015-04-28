
#ifndef FRACTOL_H

# define FRACTOL_H

#define		l_wind 800
#define		w_wind 800
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <mlx.h>
typedef struct	s_env
{
	double       	x1;
	double       	x2;
	double       	y1;
	double       	 y2;
	int		zoom;
	int		ite_max;
	int		image_x;
	int		image_y;
	int		x;
	int		y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		i;
}		t_env;

typedef struct	s_benv
{
	void		*mlx;
	void		*win;
	char		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		*img;
	int		i;
	double		factor;
	double		factorx1;
	double		factorx2;
	double		factory1;
	double		factory2;
	double			movex;
	double			movey;
}		t_benv;


int	mouse_hook(int button, int x, int y, t_benv *be);
int	key_hook(int keycode, t_benv *be);
int	coucou(t_benv be);
int	expose_hook(t_benv *be);
int	ft_keycode(int keycode, t_benv be);
t_env   ft_init_env();
void	ft_set_pixel(t_benv *be);

#endif
