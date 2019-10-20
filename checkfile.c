/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:48:21 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 01:05:27 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check(char *str)
{
	char	*line;
	int		fd;
	int		cpt;

	fd = open(str, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		return (-1);
	if (!(cpt = ft_strln(ft_strsplit(line, ' '))))
		return (0);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strln(ft_strsplit(line, ' ')) < cpt)
			return (-2);
	}
	return (1);
}

int		checkfile(char *str)
{
	int res;

	res = check(str);
	if (res == 0)
		ft_putstr("No Data found.\n");
	else if (res == -1)
	{
		ft_putstr("No file ");
		ft_putstr(str);
		ft_putstr("\n");
	}
	else if (res == -2)
		ft_putstr("Found wrong line length. Exiting\n");
	return (res);
}

void	iso_fill(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x = param->map_iso[i][j].x;
			param->map[i][j].y = param->map_iso[i][j].y;
			param->map[i][j].h = param->map_iso[i][j].h;
			param->map[i][j].k = param->map_iso[i][j].k;
			j++;
		}
		i++;
	}
}

void	parallel_fill(t_mlx *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->dim[0])
	{
		j = 0;
		while (j < param->dim[1])
		{
			param->map[i][j].x = param->map_parall[i][j].x;
			param->map[i][j].y = param->map_parall[i][j].y;
			param->map[i][j].h = param->map_parall[i][j].h;
			param->map[i][j].k = param->map_parall[i][j].k;
			j++;
		}
		i++;
	}
}
