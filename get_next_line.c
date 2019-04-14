/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:15:03 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/14 14:36:04 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **one_line)
{
	int len;
	char placeholder[BUFF_SIZE + 1];
	char *s;
	static char *storage;
	int buf;
	
	len = 0;
	
	if(!storage)
		storage = ft_strnew(0);

	while(ft_strchr(storage, '\n') == NULL)
	{
		buf = read(fd, placeholder, BUFF_SIZE);
		placeholder[buf] = '\0';
		storage = ft_strjoin(storage, placeholder);
	}

	while(storage[len] != '\n')
	{
		len++;
	}

	*one_line = ft_strsub(storage, 0, len);

//	printf("    len:|%d|\n", len);
	storage[len] = '\0';

	s = ft_strdup(&*(storage + len + 1));
//	s[ft_strlen(s)] = '\0';
//	printf("storage:|%s|\n", storage);
//	printf("      s:|%s|\n", s);
	free(storage);
	storage = ft_strdup(s);
//	storage = s;
	free(s);
//	printf("one_line:|%s|\n\n\n", *one_line);

	if(fd == -1)
		return(-1);
	else if (fd >= 1)
		return(1);
	else if(fd == 0)
		return(0);
	return(0);
}

int main (void)
{
	int fd;
	char *one_line;
	fd = open("test1.txt", O_RDONLY);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
	printf("fd:|%d|", get_next_line(fd, &one_line));
	printf("%s\n", one_line);
}

// argc, argv test
/*

int main (int argc, char **argv)
{
	int fd;
	char *one_line;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &one_line) > 0)
		printf("%s\n", one_line);
}
*/
