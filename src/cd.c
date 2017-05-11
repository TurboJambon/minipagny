/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:12:11 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/11 16:43:06 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		dir_exist(char *name)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(getpath(name));
	while ((read = readdir(dir)))
		if (ft_strcmp(read->d_name, name) == 0)
			return (0);
	return (-1);
}

void	aff_cd_errors(char *name, int i)
{
	if (i == 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(name);
		return ;
	}
	else if (i == 1)
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(name);
		return ;
	}

}

void	change_dir(char *path, char *name)
{
	struct stat stats;

	if (dir_exist(name) == -1)
		return (aff_cd_errors(name, 0));
	if (!name || ft_strcmp(name, ".") == 0)
		return ;
	lstat(path, &stats);
	if (!(stats.st_mode & S_IFDIR))
		return (aff_cd_errors(name, 1));
	if (chdir(path) == -1)
		ft_putstr("MEGABUG\n");
	perror(NULL);
}