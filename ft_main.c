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

int	main(int ac, char **av)
{
	t_benv be;

	be.factor = 1;
	be.movex = 0;
	be.movey = 0;
	be.factorx1 = 0;
	be.factorx2 = 0;
	be.stop = 0;
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
	printf("d");fflush(stdout);
	return (0);
	
}


