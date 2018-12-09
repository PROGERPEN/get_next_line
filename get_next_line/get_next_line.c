/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:16:33 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/09 15:25:40 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int		po_buff(char *buff, char **static_line, int fd, int *ret);
int check_static(char **static_line, char **line);
int		get_next_line(const int fd, char **line);


int check_static(char **static_line, char **line)
{
	char *k;
	char *new_static;

	if (!(k = ft_strchr(*static_line, '\n')))
		return (0);
	else
	{
		*k = '\0';
		*line = ft_strdup(*static_line);
		ft_memdel((void *) static_line);
		new_static = strdup((k + 1));
		*static_line = new_static;
	}
	return (1);
}

int		po_buff(char *buff, char **static_line, int fd, int *ret)
{
	while ((*ret = read (fd, buff, BUFF_SIZE)))
	{
		if (*static_line)
		{
			*static_line = ft_strjoin(*static_line, buff);
			return (1);
		}
		else
		{
			*static_line = ft_strdup(buff);
			return (1);
		}
	}
	return (0);
}


int		get_next_line(const int fd, char **line)
{
	static char *static_line = 0;
	char *buff;
	int k;
	int ret;
	ret = 0;
	buff = ft_strnew(BUFF_SIZE);
	if (!static_line)
	{
		static_line = ft_strnew(BUFF_SIZE);
		read(fd, static_line, BUFF_SIZE);
	}
	while (1)
	{
		if (check_static(&static_line, line))
			break ;
		k = po_buff(buff, &static_line, fd, &ret);
		if ((!ret) && *static_line != '\0')	
		{
			*line = strdup(static_line);
			return (1);
		}
	}

	return (0);
}



/*int		main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line = NULL;
	free(line);
	line = (char *)malloc(sizeof(char) * 30);
	argc = 0;
	    printf("ARGV: %s\n", *argv);
	get_next_line(fd, &line);
	printf("line: %s\n", line);
	free(line);
	line = (char *)malloc(sizeof(char) * 30);
	get_next_line(fd, &line);
	//printf("%d\n", get_next_line(fd, &line));
	printf("line: %s\n", line);
	free(line);
	line = NULL;
	line = (char *)malloc(sizeof(char) * 30);
	get_next_line(fd, &line);
	printf("line: %s\n", line);
	return (0);

}*/
