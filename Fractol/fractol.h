/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:39:50 by dchirol           #+#    #+#             */
/*   Updated: 2017/02/11 19:17:54 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_keys.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#define WINX 1000
#define WINY 1000


typedef struct 	s_complex
{
	double i;
	double r;
}				t_complex;

typedef struct	s_env
{
	void *mlx;
	void *win;
	void *image;
}				t_env;
