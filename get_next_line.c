/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:40 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/02 20:34:13 by mbutt            ###   ########.fr       */
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
/*
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
		printf("buf:|%d|\n", buf);
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
*/
int main (void)
{
	char dest[BUFF_SIZE];
	char **final_dest;
	int buf;
	int fd;
	int i;

	i = 0;
// How to get a file desriptor?
// open() returns a non-negative number if a file is read succesfully, which is
// the file descriptor. We store the return value of open in fd, which we will
// use in read.
	fd = open("test.txt", O_RDONLY);
//	fd = open ("/dev/random", O_RDONLY);


// Printing fd that we get from openining a file ^.
	printf("file descriptor:|%d|\n", fd);


// Understanding this while loop.
/*
	while(1)
	{
		buf = read(fd, dest, BUFF_SIZE);
		dest[buf] = '\0';
		printf("buf:|%d|\n", buf);
		if(buf < BUFF_SIZE)
		{
			printf("\nIF buf < BUFF_SIZE\n");
			printf("|%s|\n", dest);
			break;
		}
		else
			printf("ELSE buf > BUFF_SIZE\n|%s|\n\n", dest);
	}
*/
	
/*	
	read(fd, dest, BUFF_SIZE);	
	final_dest = ft_strsplit(dest, '\n');
	printf("%s", *(final_dest+2));
*/

// Put this read statement in a while loop.

// Create a placeholder to store dest characters one character at a time
// into the placeholder.
 
// We have to expand the allocated memory.

// One of the libft functios allows to reallocate memory -> which we can use
// to expand the memory for placeholder/final_dest
// With a BUFF_SIZE of 1, we cant print a full line, so we have to expand/reallocate
// memory to os placeholder/final_dest. 
// Can I use ft_strjoin to expand/ reallocate memory???
	
/*
	read(fd, dest, BUFF_SIZE);
	final_dest = ft_strsplit(dest, '\n');
	printf("%s\n", (final_dest[0]));
//	printf("%s\n", dest); // Dont use this because it doesnt split on new line
*/

	printf("BUFF_SIZE:|%d|\n", BUFF_SIZE);
	while(read(fd, dest, BUFF_SIZE))
	{
		read(fd, dest, BUFF_SIZE);
		final_dest = ft_strsplit(dest, '\n');
		printf("%s", final_dest[0]); // with a BUFF_SIZE of 32, it prints last line. Strange behavior with BUFF_SIZE of 1.
	}

//	printf("%s", *(final_dest + 1));
//	printf("%s", *(final_dest + 2));
//	printf("%s", *(final_dest + 3));

//	while(i)
//	{
//		printf("%s", *(final_dest+i));
//		i++;
//	}

/*
	fgets(dest, 32, fopen("test.txt", "r"));
	printf("%s", dest);
*/

/*	
	while((buf = read(fd, dest, BUFF_SIZE)) && dest[i] != '\n')
	{
//		if(dest[i] == '\n')
//		{
//			break;
//			i++;
//		}
//		else
//		{
		dest[buf] = '\0';
		printf("|%s|", dest);
		i++;
//		i++;
//		break;
//		}
	}
*/	
	return 0;
}
