/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David <David@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:05:12 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/11 12:29:56 by David            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_nochar(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '"')
			i++;
		else 
		{
			ft_putchar(str[i]);
			i++;
		}
	}

}

int main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar(' ');
		ft_putchar('u');
		i++;
	}
	ft_putchar('\n');
	return (0);
}