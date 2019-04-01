/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:40 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/31 20:52:55 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	get_next_line(const int fd, char **line)
{
	char **dest;

	dest = (char **)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	
	if(!dest)
		return(0);
	ft_strcpy(dest, line);

	if(!)


ssize_t		read(int fd, void *buf, size_t count);
}
*/
// Get the string from user and return it.
/* 
int main (int argc, char *argv[])
{
	char buf[BUFF_SIZE];
	int dest;

	while(1)
	{
		dest = read(0, buf, BUFF_SIZE);
		if (dest < BUFF_SIZE)
		{
			buf[dest] = '\0';
			printf("%s\n", buf);
			break;
		}
		else
			printf("%s\n", buf);
	}
	return(0);
//	source = fopen("test.txt", "r")
}
*/
/*
int main (void)
{
	char buf[BUFF_SIZE];
	int dest;
	int fd;

	fd = open("test.txt", O_RDONLY);

	while(1)
	{
		dest = read(fd, buf, BUFF_SIZE);
		buf[dest] = '\0';
		printf("%d\n",dest);
		if (dest < BUFF_SIZE)
		{
			printf("|%s|\n", buf);
			break;
		}
		else
			printf("|%s|\n", buf);
	}
	return(0);
}
*/
int main (void)
{
	char dest[BUFF_SIZE];
	int buf;
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("file descriptor:|%d|\n", fd);
	while(1)
	{
		buf = read(fd, dest, BUFF_SIZE);
		dest[buf] = '\0';
		printf("buff:|%d|\n", buf);
		if(buf < BUFF_SIZE)
		{
			printf("|%s|\n", dest);
			break;
		}
		else
			printf("|%s|\n", dest);
	}
	return 0;
}
