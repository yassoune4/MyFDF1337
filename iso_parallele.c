/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_parallele.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:52:14 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/21 23:05:34 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		point(double x, double y, double z)
{
	t_point m;

	m.x = x;
	m.y = y;
	m.k = z;
	m.h = z;
	return (m);
}

t_point		card_iso(t_point a)
{
	t_point m;

	m.x = a.x - a.y;
	m.y = (a.x + a.y) / 2 - a.h;
	m.h = a.h;
	m.k = a.h;
	return (m);
}

t_point		card_parall(t_point a)
{
	t_point m;

	m.x = a.x + (1 / 2) * a.h;
	m.y = a.y - a.h;
	m.h = a.h;
	m.k = a.h;
	return (m);
}

void		map_iso(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = -1;
		while (++j < param->dim[1])
			param->map[i][j] = card_iso(param->map[i][j]);
		i++;
	}
}

void		map_parall(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = -1;
		while (++j < param->dim[1])
			param->map[i][j] = card_parall(param->map[i][j]);
		i++;
	}
}
