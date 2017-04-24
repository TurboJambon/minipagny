/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:28:56 by niragne           #+#    #+#             */
/*   Updated: 2017/03/28 00:16:45 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	char	*new;
	size_t	size;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_strnew(size);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < size)
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < size)
		new[j++] = s2[i++];
	new[j] = '\0';
	new[j + 1] = '\0';
	ft_strdel((char**)&s1);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	t_gnl			gnl;
	int				rd;

	rd = 1;
	if (fd < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (rd != -1)
	{
		if ((gnl.tmp = ft_strchr(str[fd], '\n')) ||
			((gnl.tmp = ft_strchr(str[fd], '\0')) && !rd))
		{
			*(gnl.tmp) = '\0';
			*line = ft_strdup(str[fd]);
			ft_memmove(str[fd], gnl.tmp + 1, ft_strlen(gnl.tmp + 1) + 1);
			return ((line[0][0] || (!line[0][0] && rd)));
		}
		if ((rd = read(fd, gnl.buf, BUFF_SIZE)) == -1)
			return (-1);
		gnl.buf[rd] = '\0';
		str[fd] = ft_strjoin_free(str[fd], gnl.buf);
	}
	return (-1);
}
