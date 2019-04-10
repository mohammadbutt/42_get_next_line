/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/10 13:25:34 by mbutt            ###   ########.fr       */
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


	len = 0;
	start = 0;
	placeholder = "";
	one_line = "";

//Opens file
	fd = open("test1.txt", O_RDONLY);


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
	printf("\n\n(4A)Printing length:|%d|\n", len);
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

//(1B)	-> Reads file in a while loop
	printf("(1B)BUFF_SIZE:|%d|\n", BUFF_SIZE);
	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}
//(2B)	-> Length of placeholder
	printf("(2B)Length of placeholder:|%zu|\n", ft_strlen(placeholder));

//(3B)	-> Buffer read/placeholder	
	printf("\n(3B)Buffer read/placeholder:\n|%s|", placeholder);

//(4B)	-> Getting a single line
	while(placeholder[len] != '\n')
		len++;
	len = len - start;
	one_line = ft_strsub(placeholder, start, len);	
	printf("\n\n(4B)Printing length:|%d|\n", len);
	printf("(4B)Printing one_line:\n|%s|", one_line);
	
	start = len + 1;

//(5B)	-> Storing the line in storage
	printf("\n\n(5.0B)Before storage is trimmed:\n|%s|\n", storage);


	if((len) >= BUFF_SIZE)
	{
		printf("\n(5.1B):Printing stored characters:\n|%s|", storage);
	}
	else if ((len) < BUFF_SIZE)
	{
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
		printf("\n(5.2B):Printing stored characters:\n|%s|", storage);
	}

	printf("\n---------------------------------------------------------");
	printf("\n---------------------------------------------------------\n");


//(1C)	-> Reads file in a while loop
	printf("(1C)BUFF_SIZE:|%d|\n", BUFF_SIZE);
	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}
//(2C)	-> Length of placeholder
	printf("(2C)Length of placeholder:|%zu|\n", ft_strlen(placeholder));

//(3C)	-> Buffer read/placeholder	
	printf("\n(3C)Buffer read/placeholder:\n|%s|", placeholder);

//(4A)	-> Getting a single line
	while(placeholder[len] != '\n')
		len++;
	len = len - start;
	one_line = ft_strsub(placeholder, start, len);	
	printf("\n\n(4C)Printing length:|%d|\n", len);
	printf("(4C)Printing one_line:\n|%s|", one_line);
	
	start = len + 1;

//(5C)	-> Storing the line in storage
	printf("\n\n(5.0C)Before storage is trimmed:\n|%s|\n", storage);


	if((len) >= BUFF_SIZE)
	{
		printf("\n(5.1C):Printing stored characters:\n|%s|", storage);
	}
	else if ((len) < BUFF_SIZE)
	{
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
		printf("\n(5.2C):Printing stored characters:\n|%s|", storage);
	}

	printf("\n---------------------------------------------------------");


	return(0);
}
