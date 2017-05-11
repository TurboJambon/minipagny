/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:45:31 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/11 17:41:48 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>
# include <sys/param.h>
# include <sys/stat.h>
# define MINISHELL_H
# define BUILTINS "echo.cd.setenv.unsetenv.env.exit"
# define BUILTINS_NBR 6

int		is_in_array(char *str, char **array);
char	**builtins_launch(int i, char **env, char **entry, char **av);
void	aff_env(char **env);
char	*ft_strjoinspe(char const *s1, char const *s2);
char	*getpath(char *path);
void	change_dir(char *path, char *name);

#endif