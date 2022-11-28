/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:19 by lmarquar          #+#    #+#             */
/*   Updated: 2021/10/14 10:07:54 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static
int	khook(int key, void *param)
{
	t_args	*x;

	x = (t_args *) param;
	if (key == 65307)
	{
		mlx_destroy_image(x->mlx_ptr, x->img_ptr);
		mlx_destroy_window(x->mlx_ptr, x->win_ptr);
		mlx_loop_end(x->mlx_ptr);
		free(x->img_matrix[x->img_size - 1]);
		free(x->img_matrix);
		free(x->mlx_ptr);
		free(x);
		exit(1);
	}
	return (0);
}

static
int	mhook(int button, int x, int y, void *param)
{
	t_args	*mlx;
	int		size;

	mlx = (t_args *) param;
	size = mlx->img_size;
	if (button == 5)
		zoomin(x, y, mlx);
	else if (button == 4)
		zoomout(x, y, mlx);
	return (0);
}

static
t_args	*checkforjulia(t_args *x, int argc, char *argv[])
{
	if (argc == 3)
	{
		x->js = 1;
		x->jsx = ft_atod(argv[1]);
		x->jsy = ft_atod(argv[2]);
	}
	else if (argc == 2)
	{
		x->js = 1;
		x->jsx = ft_atod(argv[1]);
		x->jsy = 0.0;
	}
	else if (argc == 1)
		return (x);
	if (x->jsx > 2 || x->jsx < -2 || x->jsy > 2 || x->jsy < -2 || argc > 3)
	{
		write(1, "1: nothing for Mandelbrot\n", 26);
		write(1, "2: 1 double for x of Julia\n", 27);
		write(1, "3: 2 double for x and y of Julia\n", 33);
		write(1, "doubles can range from -2 to 2\n", 31);
	}
	return (x);
}

static
t_args	*createwindow(int argc, char *argv[])
{
	t_args	*x;

	x = malloc(sizeof(t_args));
	x->img_size = 500;
	x->xl = -2;
	x->xr = 2;
	x->yd = -2;
	x->yu = 2;
	x->js = 0;
	checkforjulia(x, argc, argv);
	x->mlx_ptr = mlx_init();
	x->img_ptr = mlx_new_image(x->mlx_ptr, x->img_size, x->img_size);
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->img_size, x->img_size, "name");
	x->img = mlx_get_data_addr(x->img_ptr, &x->img_bp, &x->img_sl, &x->img_e);
	x->img_matrix = creatematrix(x->img, x->img_size, x->img_sl);
	fillmatrix(x);
	return (x);
}

int	main(int argc, char *argv[])
{
	t_args	*x;

	x = createwindow(argc, argv);
	mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, x->img_ptr, 0, 0);
	mlx_key_hook(x->win_ptr, khook, x);
	mlx_mouse_hook(x->win_ptr, mhook, x);
	mlx_loop(x->mlx_ptr);
	return (0);
}
