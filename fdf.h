/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 23:39:42 by elchouai          #+#    #+#             */
/*   Updated: 2018/12/21 23:42:07 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# include "mlx.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_point
{
	long double	x;
	long double	y;
	long double	h;
	long double	k;
}				t_point;

typedef struct	s_coord
{
	int ex;
	int ey;
	int	dx;
	int	dy;
	int	dx1;
	int dy1;
	int x1;
	int y1;
}				t_coord;

typedef struct	s_mlx
{
	void	*mlx_p;
	void	*mlx_win;
	t_point	**map;
	t_point	**map_iso;
	t_point	**map_parall;
	int		*dim;
	int		flag;
	int		index;
	int		color;
}				t_mlx;

int				draw_line(t_point a, t_point b, int color, t_mlx *param);
t_point			**final_map(char *str);
t_point			**final_map_parr(char *str);
int				*dimension(char *str);
int				ft_strln(char **tab);
int				checkfile(char *str);
t_point			card_iso(t_point a);
t_point			card_parall(t_point a);
t_point			point(double x, double y, double z);
void			zoom_up(t_mlx *param);
void			zoom_down(t_mlx *param);
void			rot_rl_x(t_mlx *param, double theta);
void			rot_rl_z(t_mlx *param, double theta);
void			rot_rl_y(t_mlx *param, double theta);
void			move_up(t_mlx *param);
void			move_down(t_mlx *param);
void			move_left(t_mlx *param);
void			move_right(t_mlx *param);
void			center_map(t_mlx *param, double x, double y);
void			add_h(t_mlx *param);
void			reduce_h(t_mlx *param);
int				deal_key_1(int key, t_mlx *param);
int				deal_key_2(int key, t_mlx *param);
int				deal_key_3(int key, t_mlx *param);
int				deal_key_4(int key, t_mlx *param);
int				deal_key_5(int key, t_mlx *param);
int				deal_key(int key, t_mlx *param);
int				mlx_dealer(t_mlx *param);
void			map_iso(t_mlx *param);
void			map_parall(t_mlx *param);
int				draw_map(t_mlx *param);
void			iso_fill(t_mlx *param);
void			parallel_fill(t_mlx *param);
int				draw_horz_line(t_point a, t_point b, int ccolor, t_mlx *param);
int				draw_vert_line(t_point a, t_point b, int ccolor, t_mlx *param);
int				draw_diago_line(t_point a, t_point b, int ccolor, t_mlx *param);

#endif
