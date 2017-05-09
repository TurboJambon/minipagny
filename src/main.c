/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:16:58 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/09 20:15:14 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	(void)ac;
	char **line = malloc(9999);
	char *ptr[2];
	char *cpy = NULL;
	if (av)
	{
		;
	}
	*line = malloc(9999);
	while (1)
	{
		ft_putstr("VAS Y OUAIS>>");
		get_next_line(0, line);
		*ptr = ft_strchr(*line, ' ');
		cpy = malloc(sizeof(char) * (*ptr - *line));
		cpy = ft_strncpy(cpy, *line, *ptr - *line);
		printf("%s %s\n", cpy, *ptr);
		execve(cpy, ptr + 1, NULL);
	}
	return (0);
}
