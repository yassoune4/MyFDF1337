/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 01:09:54 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 01:09:55 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_horz_line(t_point a, t_point b, int ccolor, t_mlx *param)
{
	int j;
	int m;
	int color;

	color = (a.k == 0 && b.k == 0) ? 0xFFFFFF : ccolor;
	j = a.y;
	m = (b.y > a.y) ? 1 : -1;
	while (j != b.y)
		mlx_pixel_put(param->mlx_p, param->mlx_win, a.x, j += m, color);
	return (0);
}

int		draw_vert_line(t_point a, t_point b, int ccolor, t_mlx *param)
{
	int i;
	int m;
	int color;

	color = (a.k == 0 && b.k == 0) ? 0xFFFFFF : ccolor;
	i = a.x;
	m = (b.x > a.x) ? 1 : -1;
	while (i != b.x)
		mlx_pixel_put(param->mlx_p, param->mlx_win, i += m, a.y, color);
	return (0);
}

int		draw_diago_line(t_point a, t_point b, int ccolor, t_mlx *param)
{
	double	i;
	double	j;
	int		k;
	int		color;

	color = (a.k == 0 && b.k == 0) ? 0xFFFFFF : ccolor;
	k = -1;
	i = a.x;
	j = a.y;
	while (++k <= fabsl(a.x - b.x))
		mlx_pixel_put(param->mlx_p, param->mlx_win, i++, j++, color);
	return (0);
}
