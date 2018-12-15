/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:16:33 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/15 15:42:27 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <fcntl.h>

void	ft_free_gnl(char *static_line, char *buff)
{
	free(static_line);
	free(buff);
}

int		check_static(char **static_line, char **line)
{
	char *k;
	char *new_static;

	if (!(k = ft_strchr(*static_line, '\n')))
		return (0);
	else
	{
		*k = '\0';
		*line = ft_strdup(*static_line);
		new_static = ft_strdup((k + 1));
		ft_memdel((void *)static_line);
		*static_line = new_static;
	}
	return (1);
}

int		po_buff(char *buff, char **static_line, int fd)
{
	int		ret;
	char	*new_line;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (*static_line)
		{
			new_line = *static_line;
			*static_line = ft_strjoin(*static_line, buff);
			ft_memdel((void *)&new_line);
			return (ret);
		}
		else
		{
			new_line = *static_line;
			*static_line = ft_strdup(buff);
			ft_memdel((void *)&new_line);
			return (ret);
		}
	}
	if (ret == -1)
		ft_free_gnl(*static_line, buff);
	return (ret);
}

int		static_exist(int fd, char *buff, char **static_line, char **line)
{
	int c;

	while (1)
	{
		if (check_static(static_line, line))
			return (1);
		c = po_buff(buff, static_line, fd);
		if ((!(c)) && (**static_line != '\0'))
		{
			*line = ft_strdup(*static_line);
			free(*static_line);
			buff = NULL;
			*static_line = NULL;
			return (1);
		}
		if (c == -1)
			return (-1);
		if (!c)
			return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*static_line;
	char		*buff;
	int			k;

	if (!line)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!static_line)
	{
		static_line = ft_strnew(BUFF_SIZE);
		if (!(k = po_buff(buff, &static_line, fd)))
			ft_free_gnl(static_line, buff);
		if (k == -1)
			return (-1);
	}
	if (static_exist(fd, buff, &static_line, line) == 1)
	{
		ft_memdel((void *)&buff);
		return (1);
	}
	if (!static_exist(fd, buff, &static_line, line))
		return (0);
	if (static_exist(fd, buff, &static_line, line) == -1)
		return (-1);
	return (0);
}
