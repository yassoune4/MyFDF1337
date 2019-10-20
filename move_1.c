/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:58:11 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 00:28:57 by ysalihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_up(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	param->index = 2;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x *= param->index;
			param->map[i][j].y *= param->index;
			param->map[i][j].h *= param->index;
			j++;
		}
		i++;
	}
	param->index *= 2;
}

void	zoom_down(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x = (param->map[i][j].x / 1.1);
			param->map[i][j].y = (param->map[i][j].y / 1.1);
			param->map[i][j].h = (param->map[i][j].h / 1.1);
			j++;
		}
		i++;
	}
}

void	add_h(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].y -= param->map[i][j].k;
			j++;
		}
		i++;
	}
}

void	reduce_h(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].y += param->map[i][j].k;
			j++;
		}
		i++;
	}
}

int		ft_strln(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}
