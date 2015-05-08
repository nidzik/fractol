/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 11:41:52 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/08 17:52:11 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_benv		ft_init(t_benv be)
{
	be.factor = 1;
	be.movex = 0;
	be.movey = 0;
	be.factorx1 = 0;
	be.factorx2 = 0;
	be.stop = 0;
	be.r = 1;
	be.g = 1;
	be.b = 1;
	be.fil = 0x000000;
	be.f = 0x0000ff;
	be.ff = 0x00ff00;
	be.fff= 0xff0000;
	return (be);
}

int	main(int ac, char **av)
{
	t_benv be;

	be = ft_init(be);
	if (ac == 2)
	{
		if (av[1][0] == 'j')
			main_ju(be);
		else if (av[1][0] == 'm')
			main_mandel(be);
		else if (av[1][0] == 's')
			main_mandelship(be);
		else if (av[1][0] == 'w')
			main_mandel_wtf(be);
	}
	return (0);
	
}

int		ft_color(int keycode, t_benv *be)
{
	if (keycode == 114 || keycode == 15)
	{
		if (be->r == 0)
			be->r = 1;
		else
			be->r = 0;
	}
	if (keycode == 103 || keycode == 5)
	{
		if (be->g == 0)
			be->g = 1;
		else
			be->g = 0;
	}
	if (keycode == 98 || keycode == 11)
	{
		if (be->b == 0)
			be->b = 1;
		else
			be->b = 0;
	}
	return (0);
}

int		ft_fillb(int keycode, t_benv *be)
{
	if (keycode == 18)
	{
		if (FF > 0x00ffff)
			be->fil -= be->fff;
		else
			be->fil += be->fff;
	}
	if (keycode == 19)
	{
		if (FF != 0x00ff00 && FF != 0x00ffff && FF != 0xffff00)
			be->fil += be->ff;
		else
			be->fil -= be->ff;
	}
	if (keycode == 20)
	{
		if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
			be->fil += be->f;
		else
			be->fil -= be->f;
	}
	return (0);
}

int		ft_fillg(int keycode, t_benv *be)
{
	if (keycode == 21)
	{
		if (FF > 0x00ffff)
			be->fil -= be->fff;
		else
			be->fil += be->fff;
	}
	if (keycode == 23)
	{
		if (FF != 0x00ff00 && FF != 0x00ffff && FF != 0xffff00)
			be->fil += be->ff;
		else
			be->fil -= be->ff;
	}
	if (keycode == 22)
	{
		if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
			be->fil += be->f;
		else
			be->fil -= be->f;
	}
	return (0);
}
