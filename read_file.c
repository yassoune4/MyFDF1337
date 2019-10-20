/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:59:00 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/22 01:11:02 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*int_tab(char **tab)
{
	int *out;
	int i;

	i = 0;
	out = malloc(sizeof(int) * ft_strln(tab));
	while (tab[i] != '\0')
	{
		out[i] = ft_atoi(tab[i]);
		i++;
	}
	return (out);
}

int			*dimension(char *str)
{
	int		*t;
	int		nbr_x;
	char	*line;
	int		fd;
	int		nbr_y;

	fd = open(str, O_RDONLY);
	nbr_x = 0;
	t = (int *)malloc(sizeof(int) * 2);
	while ((get_next_line(fd, &line)) > 0)
		nbr_x++;
	nbr_y = ft_strln(ft_strsplit(line, ' '));
	close(fd);
	t[0] = nbr_x;
	t[1] = nbr_y;
	return (t);
}

int			**file_to_tab(char *str)
{
	char	*line;
	int		j;
	int		**ta;
	int		fd;
	int		*t;

	fd = open(str, O_RDONLY);
	t = dimension(str);
	ta = (int **)malloc(sizeof(int *) * (t[0] + 1));
	j = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		ta[j] = int_tab(ft_strsplit(line, ' '));
		j++;
	}
	ta[j] = NULL;
	return (ta);
}

t_point		**final_map(char *str)
{
	int			i;
	int			j;
	int			*k;
	int			**tab;
	t_point		**map;

	if (checkfile(str) != 1)
		return (NULL);
	k = dimension(str);
	tab = file_to_tab(str);
	map = (t_point **)malloc(sizeof(t_point *) * k[0]);
	i = 0;
	while (i < k[0])
	{
		j = -1;
		map[i] = (t_point *)malloc(sizeof(t_point ) * k[1]);
		while (++j < k[1])
			map[i][j] = point((double)(30 * i), (double)(-30 * j),
					(double)(3 * tab[i][j]));
		i++;
	}
	return (map);
}

t_point		**final_map_parr(char *str)
{
	int			i;
	int			j;
	int			*k;
	int			**tab;
	t_point		**map;

	if (checkfile(str) != 1)
		return (NULL);
	k = dimension(str);
	tab = file_to_tab(str);
	map = (t_point **)malloc(sizeof(t_point *) * k[0]);
	i = 0;
	while (i < k[0])
	{
		j = -1;
		map[i] = (t_point *)malloc(sizeof(t_point ) * k[1]);
		while (++j < k[1])
			map[i][j] = point(30 * j, 30 * i, 10 * tab[i][j]);
		i++;
	}
	return (map);
}
