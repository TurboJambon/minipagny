/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figuresmarrantes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 03:57:06 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/10 04:01:29 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_gomme(int x, int y, t_env *e)
{
	color = 0x00000000;
	draw(e->mlx, e->win, x, x + brushlenght, y, y + brushlenght);
	color = 0x00BB00FF;
}

void	ft_carre(int x, int y, t_env *e)
{
	draw(e->mlx, e->win, x, x + brushlenght, y, y + brushlenght);
	draw(e->mlx, e->win, x - brushlenght, x, y, y + brushlenght);
	draw(e->mlx, e->win, x - brushlenght, x, y - brushlenght, y);
	draw(e->mlx, e->win, x, x + brushlenght, y - brushlenght, y);
}

void	ft_SS(int x, int y, t_env *e)
{
		draw(e->mlx, e->win, x, x + brushlenght, y, y + brushlenght);
		draw(e->mlx, e->win, x - brushlenght * 2, x - brushlenght, y - brushlenght * 2, y - brushlenght);
		draw(e->mlx, e->win, x, x + brushlenght, y - brushlenght, y);
		draw(e->mlx, e->win, x, x + brushlenght, y - brushlenght * 2, y - brushlenght);
		draw(e->mlx, e->win, x - brushlenght, x, y - brushlenght * 2, y - brushlenght);
		draw(e->mlx, e->win, x - brushlenght * 2, x - brushlenght * 2, y - 2 * brushlenght, y + 1.5 * brushlenght);
		draw(e->mlx, e->win, x - brushlenght, x, y, y + brushlenght);
		draw(e->mlx, e->win, x - brushlenght * 2, x - brushlenght, y, y + brushlenght);
		draw(e->mlx, e->win, x - brushlenght * 2, x - brushlenght, y + brushlenght, y + brushlenght * 2);
		draw(e->mlx, e->win, x - brushlenght * 2, x - brushlenght, y + brushlenght * 2, y + brushlenght * 3);
		draw(e->mlx, e->win, x + brushlenght, x + brushlenght + brushlenght, y, y + brushlenght);
		draw(e->mlx, e->win, x + brushlenght * 2, x + brushlenght * 3, y, y + brushlenght);
		draw(e->mlx, e->win, x + brushlenght * 2, x + brushlenght * 2+ brushlenght, y - brushlenght, y);
		draw(e->mlx, e->win, x + brushlenght * 2, x + brushlenght * 3, y - brushlenght * 2, y - brushlenght);
		draw(e->mlx, e->win, x, x + brushlenght, y + brushlenght, y + brushlenght * 2);
		draw(e->mlx, e->win, x, x + brushlenght, y + brushlenght * 2, y + brushlenght * 3);
		draw(e->mlx, e->win, x + brushlenght, x + brushlenght * 2, y + brushlenght * 2, y + brushlenght * 3);
		draw(e->mlx, e->win, x + brushlenght * 2, x + brushlenght * 3, y + brushlenght * 2, y + brushlenght * 3);
}