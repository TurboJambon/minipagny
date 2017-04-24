/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:21:11 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/08 16:30:46 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void move_r(t_env *e, int value)
{
	
	
}

void	draw(void *mlx, void *win, int x, int y)
{
	static int color;
	int tmp;
	int tmpy;

	color = 0x00FF0000;
	tmp = x;
	tmpy = y;
	while (y < tmpy + 50)
	{
		while (x < tmp + 50)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		x = tmp;
		y++;
	}
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		draw(e->mlx, e->win, x, y);
	printf("%d\n", button);
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
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}