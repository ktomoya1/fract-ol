/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:38:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/14 15:13:32 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft.h"

static void	init_vars(t_vars *vars, char **argv)
{
	if (vars->type == JULIA)
	{
		vars->c.re = ft_atof(argv[2]);
		vars->c.im = ft_atof(argv[3]);
	}
	vars->x_min = -2.0;
	vars->x_max = 2.0;
	vars->y_min = -2.0;
	vars->y_max = 2.0;
	vars->mlx = mlx_init();
	if (vars->type == MANDELBROT)
		vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "mandelbrot");
	else if (vars->type == JULIA)
		vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "julia");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

static void	parse_argument(t_vars *data, int argc, char **argv)
{	
	if (argc < 2 || 4 < argc)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", STD_ERROR);
		ft_putstr_fd("Usage: ./fractol [type] [parameters]\n", STD_ERROR);
		put_error_exit("Available fractal types: mandelbrot, julia\n");
	}
	if (is_str_equal(argv[1], "mandelbrot"))
	{
		if (argc != 2)
			put_error_exit("Usage: ./fractol mandelbrot\n");
		data->type = MANDELBROT;
	}
	else if (is_str_equal(argv[1], "julia"))
	{
		if (argc != 4)
			put_error_exit("Usage: ./fractol julia [real] [imag]\n");
		data->type = JULIA;
	}
	else
	{
		ft_putstr_fd("Error: Invalid fractal type\n", STD_ERROR);
		ft_putstr_fd("Usage: ./fractol [type] [parameters]\n", STD_ERROR);
		put_error_exit("Available fractal types: mandelbrot, julia\n");
	}
}

int	fractol(int argc, char **argv)
{
	t_vars	data;

	parse_argument(&data, argc, argv);
	init_vars(&data, argv);
	draw_fractal(&data);
	mlx_hook(data.win, MOUSE_SCROLL_UP, 0, mouse_scroll, &data);
	mlx_key_hook(data.win, esc_close, &data);
	mlx_hook(data.win, DESTROY, 0, exit_on_close, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	fractol(argc, argv);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fractol");
// }
