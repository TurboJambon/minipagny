/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:12:11 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/11 17:16:19 by dchirol          ###   ########.fr       */
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

void	put_cd_errors(char *name, int i)
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

void		check_lnloop(char *path)
{
	if (!chdir(path))
		ft_putendl("Too many levels of symbolic links");
	return ;
}

void	change_dir(char *path, char *name)
{
	struct stat stats;

	if (dir_exist(name) == -1)													// CHECK SI DOSSIER EXISTE
		return (put_cd_errors(name, 0));
	if (!name || ft_strcmp(name, ".") == 0)										// CHECK SI PAS D'ARGUMENTS
		return ;
	lstat(path, &stats);
	if (!(stats.st_mode & S_IFDIR) && !(stats.st_mode & S_IFLNK))				// CHECK SI L'ARGUMENT EST UN DOSSIER
		return (put_cd_errors(name, 1));
	if (stats.st_mode & S_IFLNK)
	{																			// CHECK BOUCLE DE LIENS SYMBOLIQUES
		check_lnloop(path);
		return ;
	}
	if (chdir(path) == -1)														// EXECUTE CHDIR
		ft_putstr("MEGABUG\n");
	perror(NULL);
}