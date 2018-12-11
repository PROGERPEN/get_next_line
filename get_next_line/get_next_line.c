/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:16:33 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/11 17:51:40 by fkhrazz          ###   ########.fr       */
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
		new_static = ft_strdup((k + 1));
		ft_memdel((void *) static_line);
		*static_line = new_static;
	}
	return (1);
}

int		po_buff(char *buff, char **static_line, int fd, int *ret)
{
	char *new_line;

	while ((*ret = read (fd, buff, BUFF_SIZE)))
	{
		buff[*ret] = '\0';
		if (*static_line)
		{
			new_line = *static_line;
			*static_line = ft_strjoin(*static_line, buff);
			free(new_line);
			new_line = NULL;
			return (1);
		}
		else
		{
			new_line = *static_line;
			*static_line = ft_strdup(buff);
			free(new_line);
			new_line = NULL;
			return (1);
		}
	}
	return (0);
}

int	static_exist(int fd, char *buff, char **static_line, char **line, int *ret)
{
	while (1)
	{
		if (check_static(static_line, line))
		{
			return (1);
		}
		po_buff(buff, static_line, fd, ret);
 		if ((!(*ret)) && **static_line != '\0')	
		{
			*line = ft_strdup(*static_line);
			free(*static_line);
			free(buff);
			buff = NULL;
			*static_line = NULL; 
			return (1);
		}
		if ((*ret) == -1)
		{
			//free(buff);
			return (-1);
		}
		if (!(*ret))
			return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *static_line;
	char *buff;
	int k;
	int ret;
	ret = 0;
	if (!line)
	 return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!static_line)
	{
		static_line = ft_strnew(BUFF_SIZE);
		k = po_buff(buff, &static_line, fd, &ret);
		if (!ret)
		{
			free(static_line);
			free(buff);
			buff = NULL;
			static_line = NULL;
		 	return (0);
		}
		if (ret == -1)
		{
			free(static_line);
			free(buff);
			return (-1);
		}
	}
	if (static_exist(fd, buff, &static_line, line, &ret) == 1)
		return (1);
	if (!static_exist(fd, buff, &static_line, line, &ret))
		return (0);
	if (static_exist(fd, buff, &static_line, line, &ret) == -1)
		return (-1);
	// while (1)
	// {
	// 	if (check_static(&static_line, line))
	// 	{
	// 		return (1);
	// 	}
	// 	k = po_buff(buff, &static_line, fd, &ret);
	// 	if ((!ret) && *static_line != '\0')	
	// 	{
	// 		*line = ft_strdup(static_line);
	// 		free(static_line);
	// 		free(buff);
	// 		buff = NULL;
	// 		static_line = NULL;
	// 		return (1);
	// 	}
	// 	if (ret == -1)
	// 	{
	// 		free(buff);
	// 		return (-1);
	// 	}
	// 	if (!ret)
	// 		break ;
	// }
	// free(buff);
	return (0);
}



// int		main(int argc, char **argv)
// {
// 	int fd = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	char *line = NULL;
// 	//free(line);
// 	//line = (char *)malloc(sizeof(char) * 30);
// 	argc = 0;
// 	    printf("ARGV: %s\n", *argv);
// //	get_next_line(fd, &line);
// 	//printf("line: %s\n", line);
// //	//free(line);
// 	//line = (char *)malloc(sizeof(char) * 30);
// 	//get_next_line(fd, &line);
// 	//printf("%d\n", get_next_line(fd, &line));
// 	//printf("line: %s\n", line);
// 	//free(line);
// 	//line = NULL;
// 	//line = (char *)malloc(sizeof(char) * 200);
//     int k;
// 	while ((k = get_next_line(fd, &line) )== 1)
// 		//get_next_line(fd, &line);
// 	{
// 		printf("%d\n", k);
// 		printf("%s\n", line);
// 		//free(line);
// 	}
// 	printf("%d\n", k);
// 	return (0);
// }
