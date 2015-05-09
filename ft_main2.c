/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <bbichero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:09:32 by bbichero          #+#    #+#             */
/*   Updated: 2015/05/09 16:19:17 by bbichero         ###   ########.fr       */
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
	be.filr = 0x000000;
	be.filg = 0x000000;
	be.filb = 0x000000;
	be.f = 0x0000ff;
	be.ff = 0x00ff00;
	be.fff = 0xff0000;
	return (be);
}
