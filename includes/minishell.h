/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:45:31 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/10 18:24:47 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# include <stdio.h>
# define MINISHELL_H
# define BUILTINS "echo.cd.setenv.unsetenv.env.exit"
# define BUILTINS_NBR 6

int		is_in_array(char *str, char **array);
void	builtins_launch(int i, char **env, char **entry, char **av);
void	aff_env(char **env);
char	*ft_strjoinspe(char const *s1, char const *s2);
char	*getpath(char *path);

#endif