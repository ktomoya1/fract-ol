/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:47:19 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/13 18:17:03 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>
# include <math.h>
# include <stdbool.h>
# include <float.h>

# define MANDELBROT 1
# define JULIA 2

# define MAX_ITERATIONS 100
# define WIDTH 500
# define HEIGHT 500

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define DESTROY 17
# define KEY_ESC 53

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define STD_ERROR 2

typedef struct s_cmplx
{
	double		re;
	double		im;
}	t_cmplx;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	t_cmplx	c;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_vars;

typedef enum e_color
{
	BLACK = 0x000000,
	RED = 0xFF0000,
	YELLOW = 0xFFFF00,
	WHITE = 0xFFFFFF,
}	t_color;

void	draw_fractal(t_vars *data);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		esc_close(int keycode, t_vars *data);
int		exit_on_close(t_vars *data);
int		mouse_scroll(int button, int x, int y, t_vars *data);
t_cmplx	add_complex(t_cmplx a, t_cmplx b);
t_cmplx	mul_complex(t_cmplx a, t_cmplx b);
double	complex_abs(t_cmplx z);
double	ft_atof(const char *str);
int		put_error_exit(char *str);
bool	is_str_equal(const char *s1, const char *s2);

#endif
