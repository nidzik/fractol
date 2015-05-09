/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 11:41:52 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/09 16:33:00 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
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

int			ft_color(int keycode, t_benv *be)
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

int			ft_fillb(int keycode, t_benv *be)
{
	if (keycode == 18 || keycode == 49)
	{
		if (FF > 0x00ffff)
			be->filb -= be->fff;
		else
			be->filb += be->fff;
	}
	if (keycode == 19 || keycode == 50)
	{
		if (FF != 0x00ff00 && FF != 0x00ffff && FF != 0xffff00)
			be->filb += be->ff;
		else
			be->filb -= be->ff;
	}
	if (keycode == 20 || keycode == 51)
	{
		if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
			be->filb += be->f;
		else
			be->filb -= be->f;
	}
	return (0);
}

int			ft_fillg(int keycode, t_benv *be)
{
	if (keycode == 21 || keycode == 52)
	{
		if (FF > 0x00ffff)
			be->filg -= be->fff;
		else
			be->filg += be->fff;
	}
	if (keycode == 23 || keycode == 53)
	{
		if (FF != 0x00ff00 && FF != 0x00ffff && FF != 0xffff00)
			be->filg += be->ff;
		else
			be->filg -= be->ff;
	}
	if (keycode == 22 || keycode == 54)
	{
		if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
			be->filg += be->f;
		else
			be->filg -= be->f;
	}
	return (0);
}

int			ft_fillr(int keycode, t_benv *be)
{
	if (keycode == 21 || keycode == 55)
	{
		if (FF > 0x00ffff)
			be->filr -= be->fff;
		else
			be->filr += be->fff;
	}
	if (keycode == 23 || keycode == 56)
	{
		if (FF != 0x00ff00 && FF != 0x00ffff && FF != 0xffff00)
			be->filr += be->ff;
		else
			be->filr -= be->ff;
	}
	if (keycode == 22 || keycode == 57)
	{
		if (FF != 0x0000ff && FF != 0x00ffff && FF != 0xff00ff)
			be->filr += be->f;
		else
			be->filr -= be->f;
	}
	return (0);
}
