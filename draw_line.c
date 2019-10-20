/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 23:23:06 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 01:10:16 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	coord(t_point a, t_point b)
{
	t_coord mx;

	mx.ex = fabsl(b.x - a.x);
	mx.ey = fabsl(b.y - a.y);
	mx.dx = 2 * mx.ex;
	mx.dy = 2 * mx.ey;
	mx.dx1 = mx.ex;
	mx.dy1 = mx.ey;
	mx.x1 = (a.x > b.x) ? -1 : 1;
	mx.y1 = (a.y > b.y) ? -1 : 1;
	return (mx);
}

int		draw_case1(t_mlx *param, t_point a, t_coord mx, int color)
{
	int i;

	i = 0;
	while (i <= mx.dx1)
	{
		mlx_pixel_put(param->mlx_p, param->mlx_win, a.x, a.y, color);
		i++;
		a.x += mx.x1;
		mx.ex -= mx.dy;
		if (mx.ex < 0)
		{
			a.y += mx.y1;
			mx.ex += mx.dx;
		}
	}
	return (0);
}

int		draw_case2(t_mlx *param, t_point a, t_coord mx, int color)
{
	int i;

	i = 0;
	while (i <= mx.dy1)
	{
		mlx_pixel_put(param->mlx_p, param->mlx_win, a.x, a.y, color);
		i++;
		a.y += mx.y1;
		mx.ey -= mx.dx;
		if (mx.ey < 0)
		{
			a.x += mx.x1;
			mx.ey += mx.dy;
		}
	}
	return (0);
}

int		draw_line(t_point a, t_point b, int ccolor, t_mlx *param)
{
	t_coord	mx;
	int		i;
	int		color;

	color = (a.k == 0 && b.k == 0) ? 0xFFFFFF : ccolor;
	mx = coord(a, b);
	if (mx.dx == 0)
		return (draw_horz_line(a, b, color, param));
	if (mx.dy == 0)
		return (draw_vert_line(a, b, color, param));
	if (mx.dx == mx.dy)
		return (draw_diago_line(a, b, color, param));
	i = 0;
	if (mx.dx1 > mx.dy1)
		draw_case1(param, a, mx, color);
	else if (mx.dx1 <= mx.dy1)
		draw_case2(param, a, mx, color);
	return (0);
}
