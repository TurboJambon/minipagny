/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:16:58 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/10 21:01:39 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>

char		*ft_strjoinspe(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	char	*new;
	size_t	size;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < size)
		new[j++] = s1[i++];
	i = 0;
	new[j++] = '/';
	while (s2[i] && i < size)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*path_test(char **path, char **entry, char *pathline)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (pathline[i])
	{
		if (pathline[i] == ':')
			j++;
		i++;
	}
	i = 0;
	{	
		while (i < j)
		{
			*path = ft_strjoinspe(*path, *entry);
			if (access(*path, F_OK) == 0)
				return(*path);
				path++;
			i++;
		}
	}
	ft_putstr("zgx: command not found: ");
	ft_putendl(*entry);
	return (NULL);
}

char 	**all_path(char *path_line)
{
	return(ft_strsplit(path_line, ':'));
}

char	*get_envline(char **env, char *line) 
{
	char *ptr;
	int i;

	i = 0;
	ptr = NULL;
	while (env[i])
	{
		ptr = ft_strstr(env[i], line);
		if (ptr)
			break;
		i++;
	}
	if (ptr)
		return (ft_strchr(ptr, '=') + 1);
	else
		return (NULL);
}

char	**entry_to_tab(char **line) 
{
	char **str;

	str = ft_strsplit(*line, ' ');
	return (str);
}

void	aff_prompt(char **env)
{
	ft_putstr(GRN);
	ft_putstr(get_envline(env, "PWD"));
	ft_putchar('/');
	ft_putstr(YEL);
	ft_putstr("Zgroumax");
	ft_putstr(RED);
	ft_putstr("> ");
	ft_putstr(RESET);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	char **line = malloc(9999);
	char **paths;
	char **entry;
	char *prog_name;
	char **function_arr;
	int 	builtin;
	pid_t   papa;

	*line = malloc(9999);
	function_arr = ft_strsplit(BUILTINS, '.');
	while (ft_strcmp(*line, "exit"))
	{
		aff_prompt(env);
		get_next_line(0, line);
		if ((ft_strcmp(*line, "exit")))
		{
			entry = entry_to_tab(line);
			paths = all_path(get_envline(env, "PATH"));
			if (!(papa = fork()))
			{
				builtin = is_in_array(*entry, function_arr);
				if (builtin >= 0 && builtin <= 4)
					env = builtins_launch(builtin, env, entry, av);
				else if (execve(*entry, entry, NULL) == -1)
				{
					prog_name = path_test(paths, entry, get_envline(env, "PATH"));
					execve(prog_name, entry, NULL);
				}
			}
		}
		wait(NULL);
	}
	return (0);
}
