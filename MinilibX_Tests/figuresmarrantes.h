/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figuresmarrantes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 03:57:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/01/10 04:01:41 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"

typedef struct 	s_env
{
	void *mlx;
	void *win;

}				t_env;

void	ft_gomme(int x, int y, t_env *e);
void	ft_carre(int x, int y, t_env *e);
void	ft_SS(int x, int y, t_env *e);