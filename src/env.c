/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:24:12 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/10 18:30:53 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
#include "minishell.h"

char				*getpath(char *path)
{
	int		len;
	char	*ptr;
	char	*ret;

	if (!path)
		return (ft_strdup("."));
	len = ft_strlen(path) - 1;
	while (path[len] == '/')
		len--;
	if (!(ptr = ft_strrnchr(path, '/', len + 1)))
		return (".");
	len = ptr - path;
	ret = ft_strndup(path, len);
	return (ret);
}

int		is_in_array(char *str, char **array)
{
	int i;

	i = 0;
	while (i < BUILTINS_NBR)
	{
		if (ft_strcmp(str, array[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	builtins_launch(int i, char **env, char **entry, char **av)
{
	if (entry)
		;
	if (i == 0)
		execve(ft_strjoinspe(getpath(av[0]), ft_strjoinspe("bin", *entry)), entry, NULL);
	if (i == 4)
		aff_env(env);
}

void	aff_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}