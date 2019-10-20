/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealer_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:56:02 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/21 22:56:11 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key_1(int key, t_mlx *param)
{
	if (key == 15)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		add_h(param);
		draw_map(param);
	}
	if (key == 116)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		add_h(param);
		draw_map(param);
	}
	if (key == 121)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		reduce_h(param);
		draw_map(param);
	}
	if (key == 124)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		move_right(param);
		draw_map(param);
	}
	return (0);
}

int		deal_key_2(int key, t_mlx *param)
{
	if (key == 125)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		move_down(param);
		draw_map(param);
	}
	if (key == 126)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		move_up(param);
		draw_map(param);
	}
	if (key == 123)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		move_left(param);
		draw_map(param);
	}
	if (key == 8)
	{
		mlx_clear_window(param->mlx_p, param->mlx_win);
		param->color += 123456;
		draw_map(param);
	}
	return (0);
}

int		deal_key_3(int key, t_mlx *param)
{
	if (key == 53)
	{
		free(param);
		exit(0);
	}
	if (key == 87)
	{
		rot_rl_y(param, M_PI);
		mlx_dealer(param);
	}
	if (key == 91)
	{
		rot_rl_y(param, -M_PI);
		mlx_dealer(param);
	}
	if (key == 86)
	{
		rot_rl_x(param, M_PI);
		mlx_dealer(param);
	}
	return (0);
}

int		deal_key_4(int key, t_mlx *param)
{
	if (key == 88)
	{
		rot_rl_x(param, -M_PI);
		mlx_dealer(param);
	}
	if (key == 83 && param->flag == 0)
	{
		rot_rl_z(param, M_PI);
		mlx_dealer(param);
	}
	if (key == 69)
	{
		zoom_up(param);
		mlx_dealer(param);
	}
	if (key == 85 && param->flag == 0)
	{
		rot_rl_z(param, -M_PI);
		mlx_dealer(param);
	}
	return (0);
}

int		deal_key_5(int key, t_mlx *param)
{
	if (key == 78)
	{
		zoom_down(param);
		mlx_dealer(param);
	}
	if (key == 49)
	{
		if (param->flag == 0)
		{
			parallel_fill(param);
			map_parall(param);
			mlx_dealer(param);
			param->flag = 1;
		}
		else
		{
			iso_fill(param);
			map_iso(param);
			mlx_dealer(param);
			param->flag = 0;
		}
	}
	return (0);
}
