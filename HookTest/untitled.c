

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

int key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
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