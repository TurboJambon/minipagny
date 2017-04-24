/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:02:05 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/11 19:21:23 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_trace_mendelbrot(t_env e, double zoom, double moveX, double moveY, float xmo, float ymo, int imax)
{
	t_complex 	c;
	t_complex 	new;
	float 		tmp;
	float 		x;
	float 		y;
	int 		i;

	y = 0;
	while (y < WINY)
	{
		c.i = (y - ymo - WINY / 2) / (zoom * WINY + ymo) + moveY;
		x = 0;
		while (x < WINX)
		{
			c.r = (x - xmo - WINX / 2) / (zoom * WINX + xmo) + moveX;
			//c.i = ((y - (WINY /2)) / (0.5 * zoom * WINY)) + moveY;
			//c.r = (((x - xmo) * zoom) - xmo + moveX) / (WINX / 2) ;
			new.r = 0;
			new.i = 0;
			tmp = 0;
			i = 0;
			while (i < imax && new.r * new.r + new.i * new.i < 4)
			{
				tmp = 2 * new.r * new.i + c.i;
				new.r = new.r * new.r - new.i * new.i + c.r;
				new.i = tmp;
				i++;
			}
			if (i != imax)
				mlx_pixel_put(e.image, e.win, x, y, 0x0F0000 + (i * 255 / imax));
			x++;
		}
		y++;
	}
}

int mouse_hook(int button, int x, int y ,t_env *e)
{
	static double zoom = 0.8;
	static double value = 0.1;
	static int imax = 150;
	printf("%d\n", button);

	if (button == 2 && x >= 0 && x <= WINX
		&& y >= 0 && y <= WINY)
	{
		zoom *= 0.8;
		imax += 5;
		mlx_clear_window(e->mlx, e->win);
		ft_trace_mendelbrot(*e, zoom, -0.5, 0, x, y, imax);
		printf("%d, %d\n", x, y);
	}
	else if (button == 1)
	{
		zoom /= 0.8;
		imax -= 5;
		mlx_clear_window(e->mlx, e->win);
		ft_trace_mendelbrot(*e, zoom, -0.5, 0, x, y, imax);
		printf("%d, %d\n", x, y);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_env e;
	static int zoom;

	zoom = 5;
	e.mlx = mlx_init();	
	e.win = mlx_new_window(e.mlx, WINX, WINY, "Fract'ol");
	e.image = mlx_new_image(e.mlx, WINX, WINY);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	ft_trace_mendelbrot(e, 1, -0.5, 0, 700, 500, 150);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}