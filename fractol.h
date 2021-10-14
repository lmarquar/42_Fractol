/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:55:59 by lmarquar          #+#    #+#             */
/*   Updated: 2021/10/08 09:58:07 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_args
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img;
	char	***img_matrix;
	int		img_bp;
	int		img_sl;
	int		img_e;
	int		img_size;
	double	xl;
	double	xr;
	double	yd;
	double	yu;
	int		js;
	double	jsx;
	double	jsy;
	int		x;
	int		y;
	int		color;
}	t_args;

int		putcolors(t_args *mlx, int y, int row, int col);
char	***creatematrix(char *img, int img_size, int img_sl);
int		fillmatrix(t_args *mlx);
int		zoomout(int x, int y, t_args *mlx);
int		zoomin(int x, int y, t_args *mlx);
double	ft_atod(char *nptr);

#endif