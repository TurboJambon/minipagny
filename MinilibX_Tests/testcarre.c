/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcarre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 02:09:40 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/02 22:54:13 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figuresmarrantes.h"

int brushlenght = 100;
char flag = 'a';
int color = 0x00BB00FF;

void	draw(void *mlx, void *win, int x, int x2, int y, int y2)
{
	int tmp;

	tmp = x;
	while (y < y2)
	{
		while (x < x2)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		x = tmp;
		y++;
	}
	color += 50;
	color += 0x000B0010;
}

int expose_hook(t_env *e)
{
	int x = 100;
	int y = 100;
	int x2 = 300;
	int y2 = 300;
	draw(e->mlx, e->win, x, x2, y, y2);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d\n - %d / %d", button, x ,y);
	if (button == 1 || button == 4 || button == 5)
		draw(e->mlx, e->win, x, x + brushlenght, y, y + brushlenght);
	if (button == 2 && flag == 's')
		ft_SS(x, y, e);
	if (button == 2 && flag == 'a')
		ft_carre(x, y, e);
	if ((button == 1 || button == 4 || button == 5) && flag == 'g')
		ft_gomme(x, y, e);
	return (0);
}	

int key_hook(int keycode, t_env *e)
{
	static int x = 100;
	static int y = 100;
	static int i = 0;
	int x2 = x + 100 + i;
	int y2 = y + 100 + i;
	if (x == 500)
		x = 100;
	if (y == 100)
		y = 100;
	printf("key : %d\n", keycode);
	if (keycode == 1)
		flag = 's';
	if (keycode == 0)
		flag = 'a';
	if (keycode == 53)
		exit(0);
	if (keycode == 82)
		brushlenght = 5;
	if (keycode == 83)
		brushlenght = 10;
	if (keycode == 84)
		brushlenght = 15;
	if (keycode == 85)
		brushlenght = 20;
	if (keycode == 90)
		brushlenght = 50;
	if (keycode == 69)
		brushlenght += 10;
	if (keycode == 78)
		brushlenght -= 10;
	if (keycode == 5)
		flag = 'g';
	x += 100;
	x2 += 100;
	i +=10;
	return (0);
}

int main()
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1400, 900, "mlx 42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);

	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}