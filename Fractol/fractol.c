/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:21:11 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/11 17:01:43 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_trace_mendelbrot(t_env e, float zoom, int dirx, int diry, int x, int y)
{
	t_complex c;
	t_complex z;
	float x1 = -2.1;
	float x2 = 0.6;
	float y1 = -1.2;
	float y2 = 1.2;
	int imagex = (54 * zoom);
	int imagey = (48 * zoom);
	int imax = 80;
	int i; 
	float tmp;
	float zoomx;
	float zoomy;
	int tmpx = x;
	int tmpy = y;
	int bite = 0;
	int couille = 0;
	static char a = 'a';

	zoomx = imagex / (x2 - x1) ;
	zoomy = imagey / (y2 - y1) ;
	
	x = tmpx;
	while (bite < dirx)
	{
		y = tmpy; 
		while (couille < diry)
		{
			c.r = x / zoomx + x1;
			c.i = y / zoomy + y1;
			z.r = 0;
			z.i = 0;
			i = 0;
			while ((z.r * z.r + z.i * z.i) < 4 && i < imax)
			{
				tmp = z.r;
				z.r = (z.r * z.r) - (z.i * z.i) + c.r;
				z.i = 2 * z.i * tmp + c.i;
				i++;
			}
			if (i != imax)
				mlx_pixel_put(e.image, e.win, x - dirx, y - diry, 0x000000 + (i * 255 / imax));
			y++;
			couille++;
		}
		bite++;
		x++;
	}
	printf("\nxmax = %d\n", x);
	printf("ymax = %d\n", y);
	printf("dirx = %d\n", dirx);
	printf("diry = %d\n", diry);
	printf("%c\n", a++);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	static float zoom = 8;
	static int dirx = 0;
	static int diry = 0;

	if (button == 1)
	{
		zoom += 2;
		mlx_clear_window(e->mlx, e->win);
		ft_trace_mendelbrot(*e, zoom, dirx, diry, x, y);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	static float zoom = 8;
	static int dirx = 0;
	static int diry = 0;
	int x = 0;
	int y = 0;

	printf("%d", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
		ft_trace_mendelbrot(*e, zoom, dirx, diry, x, y);
	else if (keycode == 259)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == KEY_PAD_SUB)
	{
		zoom -= 2;
		mlx_clear_window(e->mlx, e->win);
		ft_trace_mendelbrot(*e, zoom, dirx, diry, x, y);
	}
	else if (keycode == KEY_PAD_ADD)
	{
		zoom += 2;
		mlx_clear_window(e->mlx, e->win);
		ft_trace_mendelbrot(*e, zoom, dirx, diry, x, y);
	}
	return (0);
}

int main()
{
	t_env e;

	static int zoom;

	zoom = 5;
	e.mlx = mlx_init();	
	e.win = mlx_new_window(e.mlx, WINX, WINY, "banane");
	e.image = mlx_new_image(e.mlx, WINX, WINY);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	ft_trace_mendelbrot(e, zoom, 0, 0, 0, 0);	
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}