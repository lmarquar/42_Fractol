/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:29 by lmarquar          #+#    #+#             */
/*   Updated: 2021/10/08 09:57:28 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	***creatematrix(char *img, int img_size, int img_sl)
{
	int		i;
	char	*ptr;
	char	**pptr;
	char	***ppptr;

	ptr = img;
	pptr = malloc(sizeof(char *) * img_size * img_size);
	i = 0;
	while (ptr < (img + img_size * img_sl))
	{
		pptr[i++] = ptr;
		ptr = ptr + 4;
	}
	i = 0;
	ppptr = malloc(img_size * sizeof(char **));
	i = img_size - 1;
	while (i >= 0)
	{
		ppptr[i--] = pptr;
		pptr = pptr + img_size;
	}
	return (ppptr);
}

int	zoomin(int x, int y, t_args *mlx)
{
	double	xcomb;
	int		size;

	size = mlx->img_size;
	xcomb = (mlx->xr - mlx->xl) / 4.0;
	mlx->xl = (mlx->xl + ((xcomb * ((double) x / size))));
	mlx->yu = (mlx->yu - ((xcomb * ((double) y / size))));
	mlx->xr = (mlx->xr - ((xcomb * ((double)(size - x) / size))));
	mlx->yd = (mlx->yd + ((xcomb * ((double)(size - y) / size))));
	fillmatrix(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}

int	zoomout(int x, int y, t_args *mlx)
{
	double	xcomb;
	int		size;

	size = mlx->img_size;
	xcomb = (mlx->xr - mlx->xl) / 4.0;
	mlx->xl = (mlx->xl - ((xcomb * ((double)(size - x) / size))));
	mlx->yu = (mlx->yu + ((xcomb * ((double)(size - y) / size))));
	mlx->xr = (mlx->xr + ((xcomb * ((double) x / size))));
	mlx->yd = (mlx->yd - ((xcomb * ((double) y / size))));
	fillmatrix(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}

static
double	getvalue(t_args *mlx, double x, double z)
{
	double	yx;
	double	yxx;
	double	yz;
	int		i;

	yx = x;
	yxx = x;
	yz = z;
	if (mlx->js)
	{
		x = mlx->jsx;
		z = mlx->jsy;
	}
	i = 100;
	while (i > 0)
	{
		if ((pow(yx, 2) + pow(yz, 2)) > 4)
			return (i);
		yxx = (yx * yx - yz * yz) + x;
		yz = (double)2 * yx * yz + z;
		yx = yxx;
		i--;
	}
	return (0);
}

int	fillmatrix(t_args *mlx)
{
	int		row;
	int		col;
	double	x;
	double	z;
	double	v;

	row = -1;
	col = -1;
	while (++row < mlx->img_size)
	{
		z = (double)(mlx->img_size / (mlx->yu - mlx->yd));
		z = (((double)row / z) + (double)mlx->yd);
		while (++col < mlx->img_size)
		{
			x = (double)(mlx->img_size / (mlx->xr - mlx->xl));
			x = ((double)col / x) + (double)mlx->xl;
			v = getvalue(mlx, x, z);
			putcolors(mlx, v, row, col);
		}
		col = -1;
	}
	return (0);
}
