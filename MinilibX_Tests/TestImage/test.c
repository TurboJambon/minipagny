/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:17:45 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/26 16:32:18 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_env
{
	void *mlx;
	void *win;
	void *image;
}				t_env;

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

int main()
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1400, 900, "mlx 42");
	e.image = mlx_new_image(e.mlx, 1400, 900);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}