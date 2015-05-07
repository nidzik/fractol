/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 11:41:52 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/07 17:00:36 by lebijuu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_benv		ft_init(t_benv)
{
	be.factor = 1;
	be.movex = 0;
	be.movey = 0;
	be.factorx1 = 0;
	be.factorx2 = 0;
	be.stop = 0;
	be.r = 0;
	be.g = 0;
	be.b = 0;
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
	if (keycode == 114)
	{
		if (be.r == 0)
			be.r = 1;
		else
			be.r = 0;
	}
	if (keycode == 103)
	{
		if (be.g == 0)
			be.g = 1;
		else
			be.g = 0;
	}
	if (keycode == 98)
	{
		if (be.b == 0)
			be.b = 1;
		else
			be.b = 0;

	}
	return (0);
}
