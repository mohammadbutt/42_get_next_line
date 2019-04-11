/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/11 13:44:58 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int start;
	int fd;
	int len;
	char *placeholder;
	char storage[BUFF_SIZE + 1];
	char *one_line;
	int skip_line;
	int increment;

	len = 0;
	start = 0;
	placeholder = "";
	one_line = "";
	skip_line = 2;
	increment = 0;

//Opens file
	fd = open("test1.txt", O_RDONLY);

//Works - reads and prints the first line perfectly and stores the lines upto BUFF_SIZE
/*
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
*/

//(1A)	-> Reads file in a while loop
	printf("(1A)BUFF_SIZE:|%d|\n", BUFF_SIZE);
		while(skip_line >= 0)
		{
			if(ft_strchr(storage, '\n'))
			while((ft_strchr(storage, '\n') == NULL))
			{
				read(fd, storage, BUFF_SIZE);
				storage[BUFF_SIZE] = '\0';
				placeholder = ft_strjoin(placeholder, storage);
			}
			skip_line--;
			increment++;
		}
//		increment++;
//		skip_line--;
//	}
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

	return(0);
}
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
