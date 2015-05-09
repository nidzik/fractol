/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <bbichero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:39:38 by bbichero          #+#    #+#             */
/*   Updated: 2015/05/09 16:52:31 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define FF		(be->f + be->ff + be->fff)
# define L_WIND	800
# define W_WIND	800

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_env
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			zoom;
	int			ite_max;
	int			image_x;
	int			image_y;
	int			x;
	int			y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		i;
}				t_env;

typedef struct	s_benv
{
	void		*mlx;
	void		*win;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			*img;
	int			i;
	double		factor;
	double		factorx1;
	double		factorx2;
	double		factory1;
	double		factory2;
	double		movex;
	double		movey;
	int			stop;
	int			filr;
	int			filg;
	int			filb;
	int			f;
	int			ff;
	int			fff;
	int			r;
	int			g;
	int			b;
}				t_benv;

t_benv			ft_init(t_benv be);
int				ft_color(int keycode, t_benv *be);
int				ft_fillr(int keycode, t_benv *be);
int				ft_fillg(int keycode, t_benv *be);
int				ft_fillb(int keycode, t_benv *be);
int				mouse_hook_ju(int button, int x, int y, t_benv *be);
int				key_hook_ju(int keycode, t_benv *be);
int				call_ju(t_benv be);
int				expose_hook_ju(t_benv *be);
t_env			ft_init_env_ju(t_benv be);
void			ft_draw_ju(t_benv *be);
int				main_ju(t_benv be);
int				motion_hook(int x, int y, t_benv *be);
int				mouse_hook_mandel(int button, int x, int y, t_benv *be);
int				key_hook_mandel(int keycode, t_benv *be);
int				call_mandel(t_benv be);
int				expose_hook_mandel(t_benv *be);
t_env			ft_init_env_mandel(t_benv be);
void			ft_draw_mandel(t_benv *be);
int				motion_hook_mand(int x, int y, t_benv *be);
int				main_mandel(t_benv be);
int				mouse_hook_mandelship(int button, int x, int y, t_benv *be);
int				key_hook_mandelship(int keycode, t_benv *be);
int				call_mandelship(t_benv be);
int				expose_hook_mandelship(t_benv *be);
t_env			ft_init_env_mandelship(t_benv be);
void			ft_draw_mandelship(t_benv *be);
int				main_mandelship(t_benv be);
int				mouse_hook_mandel_wtf(int button, int x, int y, t_benv *be);
int				key_hook_mandel_wtf(int keycode, t_benv *be);
int				call_mandel_wtf(t_benv be);
int				expose_hook_mandel_wtf(t_benv *be);
t_env			ft_init_env_mandel_wtf(t_benv be);
void			ft_draw_mandel_wtf(t_benv *be);
int				main_mandel_wtf(t_benv be);

#endif
