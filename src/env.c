/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:24:12 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/30 16:34:37 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
#include "minishell.h"

int		get_envlinepos(char **env, char *line) 
{
	char *ptr;
	int i;

	i = 0;
	ptr = NULL;
	while (env[i])
	{
		ptr = ft_strstr(env[i], line);
		if (ptr)
			return(i);
		i++;
	}
	return (-1);
}

char		**set_env(char **env, char **entry)
{
	int i;
	int j;
	int size;
	char **new_env;

	size = 0;
	i = 0;
	j = 0;

	if ((j = (get_envlinepos(env, ft_strsplit(entry[1], '=')[0]))))
	{
		if (j == -1)
			j = 0;
	}
	while (env[size])
			size++;
	if (!(new_env = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	if (!j)
	{
		while (i < size - 1)
		{
			new_env[i] = ft_strdup(env[i]);
			i++;
		}
		new_env[i] = ft_strdup(entry[1]);
		i++;
		new_env[i] = ft_strdup(env[i - 1]);
	}
	else 
	{
		while (i < j)
		{
			new_env[i] = ft_strdup(env[i]);
			i++;
		}
		new_env[i] = ft_strdup(entry[1]);
		printf("%s, %s, %s\n", new_env[i], env[i], entry[1]);
		i++;
		while (i < size)
		{
			new_env[i] = ft_strdup(env[i]);
			i++;
		}
	}
	return (new_env);
}

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

char	**builtins_launch(int i, char **env, char **entry, char **av)
{
	(void)av;
	if (i == 0) 		/* ECHO	*/
		execve(ft_strjoinspe(getpath(av[0]), ft_strjoinspe("bin", *entry)), entry, NULL);
	else if (i == 1) 	/*  CD 	*/
			change_dir(ft_strjoinspe(getcwd(av[0], MAXPATHLEN), entry[1]), entry[1]);
	else if (i == 2)	/*SETENV*/
		env = set_env(env, entry);
	else if (i == 4)	/* ENV	*/
		aff_env(env);	
	return (env);
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