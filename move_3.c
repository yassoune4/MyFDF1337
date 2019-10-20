/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:58:42 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 00:36:01 by ysalihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_rl_y(t_mlx *param, double theta)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			x = param->map[i][j].x;
			z = param->map[i][j].h;
			param->map[i][j].h = z * cos(theta) - x * sin(theta);
			param->map[i][j].x = z * sin(theta) + x * cos(theta);
			j++;
		}
		i++;
	}
}

void	rot_rl_x(t_mlx *param, double theta)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			y = param->map[i][j].y;
			z = param->map[i][j].h;
			param->map[i][j].h = y * sin(theta) + z * cos(theta);
			param->map[i][j].y = y * cos(theta) - z * sin(theta);
			j++;
		}
		i++;
	}
}

void	rot_rl_z(t_mlx *param, double theta)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			x = param->map[i][j].x;
			y = param->map[i][j].y;
			param->map[i][j].x = x * cos(theta) - y * sin(theta);
			param->map[i][j].y = y * cos(theta) + x * sin(theta);
			j++;
		}
		i++;
	}
}

int		deal_key(int key, t_mlx *param)
{
	deal_key_1(key, param);
	deal_key_2(key, param);
	deal_key_3(key, param);
	deal_key_4(key, param);
	deal_key_5(key, param);
	return (0);
}

int		mlx_dealer(t_mlx *param)
{
	mlx_clear_window(param->mlx_p, param->mlx_win);
	center_map(param, (WIN_WIDTH) / 2, (WIN_HEIGHT) / 2);
	draw_map(param);
	return (0);
}
