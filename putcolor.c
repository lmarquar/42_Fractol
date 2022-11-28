/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <leon.marquardt@gmx.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:56:22 by lmarquar          #+#    #+#             */
/*   Updated: 2021/10/05 17:56:23 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*changes the colorvalues, set to go from 0 to 100:
** 0 is black, 100 is white
** colorcode: bgr0
*/

static
int	putcolors4(t_args *mlx, int y, int row, int col)
{
	if (y < 100)
	{
		(mlx->img_matrix)[row][col][0] = (char)255;
		(mlx->img_matrix)[row][col][1] = (char)((y - 90) * 24);
		(mlx->img_matrix)[row][col][2] = (char)255;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else if (y == 100)
	{
		(mlx->img_matrix)[row][col][0] = (char)255;
		(mlx->img_matrix)[row][col][1] = (char)255;
		(mlx->img_matrix)[row][col][2] = (char)255;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	return (1);
}

static
int	putcolors3(t_args *mlx, int y, int row, int col)
{
	if (y < 70)
	{
		(mlx->img_matrix)[row][col][0] = (char)255;
		(mlx->img_matrix)[row][col][1] = (char)((y - 50) * 12);
		(mlx->img_matrix)[row][col][2] = (char)0;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else if (y < 90)
	{
		(mlx->img_matrix)[row][col][0] = (char)255;
		(mlx->img_matrix)[row][col][1] = (char)0;
		(mlx->img_matrix)[row][col][2] = (char)((y - 70) * 12);
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else
		putcolors4(mlx, y, row, col);
	return (1);
}

static
int	putcolors2(t_args *mlx, int y, int row, int col)
{
	if (y < 30)
	{
		(mlx->img_matrix)[row][col][0] = (char)0;
		(mlx->img_matrix)[row][col][1] = (char)0;
		(mlx->img_matrix)[row][col][2] = (char)255;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else if (y < 50)
	{
		(mlx->img_matrix)[row][col][0] = (char)0;
		(mlx->img_matrix)[row][col][1] = (char)((y - 30) * 12);
		(mlx->img_matrix)[row][col][2] = (char)0;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else
		putcolors3(mlx, y, row, col);
	return (1);
}

int	putcolors(t_args *mlx, int y, int row, int col)
{
	if (y == 0)
	{
		(mlx->img_matrix)[row][col][0] = (char)0;
		(mlx->img_matrix)[row][col][1] = (char)0;
		(mlx->img_matrix)[row][col][2] = (char)0;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else if (y < 20)
	{
		(mlx->img_matrix)[row][col][0] = (char)(y * 12);
		(mlx->img_matrix)[row][col][1] = (char)0;
		(mlx->img_matrix)[row][col][2] = (char)0;
		(mlx->img_matrix)[row][col][3] = 0;
	}
	else
		putcolors2(mlx, y, row, col);
	return (1);
}
