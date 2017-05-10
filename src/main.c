/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:16:58 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/10 17:09:05 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

char	*path_test(char **path, char **entry, char *pathline) // TEST
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
	ft_putstr("sa exist pa ta merd\n");
	return (NULL);
}

char 	**all_path(char *path_line)
{
	return(ft_strsplit(path_line, ':'));
}

char	*get_envline(char **env, char *line) 
{
	/* RECUPERE UNE LIGNE DE L'ENV*/
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
	return (ptr + 5);
}

char	**entry_to_tab(char **line) 
{
	/* RECUPERE L'ENTREE ET LA MET DANS UN DOUBLE TABLEAU */
	char **str;

	str = ft_strsplit(*line, ' ');
	return (str);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char **line = malloc(9999);
	char **paths;
	char **entry;
	char *prog_name;

	*line = malloc(9999);
	while (1)
	{
		ft_putstr("Zgourmax >");
		get_next_line(0, line);
		entry = entry_to_tab(line);
		paths = all_path(get_envline(env, "PATH"));
		prog_name = path_test(paths, entry, get_envline(env, "PATH"));
		if (fork() == 0)
			execve(prog_name, entry, NULL);
		wait(NULL);
	}
	return (0);
}
