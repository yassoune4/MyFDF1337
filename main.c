/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:57:42 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 01:04:25 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_header(t_mlx *param)
{
	mlx_string_put(param->mlx_p, param->mlx_win, 50, 20, 0xFFFFFF,
			"use arrows for moves");
	mlx_string_put(param->mlx_p, param->mlx_win, 50, 40, 0xFFFFFF,
			"6:4 - 8:5 - 1:3 -> make rotation");
	mlx_string_put(param->mlx_p, param->mlx_win, 50, 60, 0xFFFFFF,
			"+ : - -> Zoom in  Zoom out");
	mlx_string_put(param->mlx_p, param->mlx_win, 50, 80, 0xFFFFFF,
			"Pageup:pagedown -> add or reduce attitude");
	mlx_string_put(param->mlx_p, param->mlx_win, 50, 100, 0xFFFFFF,
			"c -> change color");
	return (0);
}

int		draw_map(t_mlx *param)
{
	int i;
	int j;

	draw_header(param);
	i = -1;
	while (++i < param->dim[0])
	{
		j = -1;
		while (++j < param->dim[1])
		{
			if (i + 1 < param->dim[0])
				draw_line(param->map[i][j], param->map[i + 1][j],
						param->color, param);
			if (j + 1 < param->dim[1])
				draw_line(param->map[i][j], param->map[i][j + 1],
						param->color, param);
		}
	}
	return (0);
}

void	fillthemlx(t_mlx *param)
{
	int i;

	i = -1;
	param->flag = 0;
	param->map = malloc(sizeof(t_point *) * param->dim[0]);
	while (++i < param->dim[0])
		param->map[i] = malloc(sizeof(t_point) * param->dim[1]);
	param->color = 0x0000FF;
	param->mlx_p = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx_p, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

int		main(int argc, char **argv)
{
	t_mlx *param;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	param = (t_mlx *)malloc(sizeof(t_mlx));
	param->dim = dimension(argv[1]);
	if ((param->map_iso = final_map(argv[1])) == NULL)
		return (0);
	if ((param->map_parall = final_map_parr(argv[1])) == NULL)
		return (0);
	fillthemlx(param);
	iso_fill(param);
	map_iso(param);
	center_map(param, (WIN_WIDTH) / 2, (WIN_HEIGHT) / 2);
	draw_map(param);
	mlx_hook(param->mlx_win, 2, 0, deal_key, param);
	mlx_loop(param->mlx_p);
	return (0);
}
