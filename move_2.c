/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:58:24 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 00:34:17 by ysalihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].y -= 10;
			j++;
		}
		i++;
	}
}

void	move_down(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].y += 10;
			j++;
		}
		i++;
	}
}

void	move_left(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x -= 10;
			j++;
		}
		i++;
	}
}

void	move_right(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x += 10;
			j++;
		}
		i++;
	}
}

void	center_map(t_mlx *param, double x, double y)
{
	int i;
	int j;
	int diff_y;
	int diff_x;

	diff_x = x - param->map[param->dim[0] / 2][param->dim[1] / 2].x;
	diff_y = y - param->map[param->dim[0] / 2][param->dim[1] / 2].y;
	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x += diff_x;
			param->map[i][j].y += diff_y;
			j++;
		}
		i++;
	}
}
