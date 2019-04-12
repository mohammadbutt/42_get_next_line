/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/11 20:02:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int main (void)
{
	int start;
	int fd;
	int len;
	char *placeholder;
	char storage[BUFF_SIZE + 1];
	char *one_line;
//	int skip_line;
//	int increment;
//	int i;

	len = 0;
	start = 0;
	placeholder = "";
	one_line = "";
//	skip_line = 1;
//	increment = 0;
//	i = 0;

//Opens file
	fd = open("test3.txt", O_RDONLY);
	printf("File descriptor:|%d|\n", fd);
//Works - reads and prints the first line perfectly and stores the lines upto BUFF_SIZE

//(1A)	-> Reads file in a while loop
	printf("(1A)BUFF_SIZE:|%d|\n", BUFF_SIZE);
	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}
//(2A)	-> Length of placeholder
	printf("(2A)Length of placeholder:|%zu|\n", ft_strlen(placeholder));

//(3A)	-> Buffer read/placeholder	
	printf("\n(3A)Buffer read/placeholder:\n|%s|", placeholder);

//(4A)	-> Getting a single line
	while(placeholder[len] != '\n')
		len++;
	len = len - start;
	one_line = ft_strsub(placeholder, start, len);	
	printf("\n\n(4A)len before subtracting from start:|%d|\n", len);
	printf("(4A)start:|%d|\n", start);
	printf("(4A)Printing length:|%d|\n", len);
	printf("(4A)Printing one_line:\n|%s|", one_line);
	
	start = len + 1;

//(5A)	-> Storing the line in storage
	printf("\n\n(5.0A)Before storage is trimmed:\n|%s|\n", storage);


	if((len) >= BUFF_SIZE)
	{
		printf("\n(5.1A):Printing stored characters:\n|%s|", storage);
	}
	else if ((len) < BUFF_SIZE)
	{
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
		printf("\n(5.2A):Printing stored characters:\n|%s|", storage);
	}


	printf("\n---------------------------------------------------------");
	printf("\n---------------------------------------------------------");
	printf("\n---------------------------------------------------------\n");

	return(0);
}
*/
/* From Fransisco
int	main(void)
{
	char *ptr;
	int fd;
	fd = open("hello.txt", O_RDONLY);
	printf("%d\n", fd);
	while (get_next_line(fd, &ptr) > 0)
	{
		printf("[%s]\n", ptr);
		ft_strdel(&ptr);
	}
	return (0);
}
*/

int		get_next_line(const int fd, char **one_line)
{
	int start;
//	int fd;
	int len;
	char *placeholder;
	static char storage[BUFF_SIZE + 1];
//	char **one_line;

	len = 0;
	start = 0;
	placeholder = "";
	//one_line = "";

	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}

	while(placeholder[len] != '\n')
		len++;
	len = len - start;
	*one_line = ft_strsub(placeholder, start, len);	

	if ((len) < BUFF_SIZE)
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
	printf("\n|%s|\n", storage);
//	return(one_line);


	if(fd == -1)
		return(-1);
	else if(fd >= 1)
		return(1);
	return(0);
}

int main (void)
{
	int fd;
	char *one_line;
	fd = open("test3.txt", O_RDONLY);
	
	printf("%d\n", fd);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	free(one_line);
	get_next_line(fd, &one_line);
//	printf("%s", one_line);

	return(0);
}

