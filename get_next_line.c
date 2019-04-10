/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:24:02 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/09 20:14:41 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int get_next_line(const int fd, char **line)
{
	char **dest;
	dest = (char **)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if(!dest)
		return(0);
}
*/
int main (void)
{
//	char dest[BUFF_SIZE + 1];
//	int buf;
	int fd;
	int len;
	char *placeholder;
	char storage[BUFF_SIZE + 1];
	char *one_line;
	
	placeholder = "";
//	storage = "";
	one_line = "";
	len = 0;


//	fd = open("test2.txt", O_RDONLY);
	fd = open("test1.txt", O_RDONLY);
	printf("BUFF_SIZE:|%d|\n", BUFF_SIZE);

// -- Reads and prints the entire file no matter what the BUFF_SIZE is.
/*
	while((buf = read(fd, dest, BUFF_SIZE)))
	{
		while (dest[i])
		{
	//		dest[buf] = '\0';
			printf("%s\n", dest);
	//		printf("%c", dest[i]);
			i++;
		}
//		if(dest[i] == '\n')
//			break;
	}
*/
		// - Prints as many words as the buffer_size
/*	
	while((buf = read(fd, dest, BUFF_SIZE)))
	{
		final_dest = ft_strsplit(dest, '\n');
		final_dest[buf] = NULL;
		printf("%s", final_dest[1]);
		i++;
		break;
	}
*/	
// - Prints single character
/*
	while ((buf = read(fd, dest, BUFF_SIZE)))
	{
		final_dest = ft_strsplit(dest, '\n');
		printf("%c", final_dest[0][0]);
		break;
	}
*/
/*	
	while ((buf = read(fd, dest, BUFF_SIZE)))
	{
		final_dest = ft_strsplit(dest, '\n');
		if(final_dest[0][0] != '\n')
		{
			printf("%s\n", final_dest[0]);
		}
//		else if (final_dest[0][0] == '\n')
//		{
//			break;
//		}
	}
*/	
//	 Prints a single line perfectly, but only when the BUFF_SIZE is 1.
//	while ((buf = read(fd, dest, BUFF_SIZE)))
//	iwhile((read(fd, dest, BUFF_SIZE)) && dest[0] != "\n")
//	{
//		printf("%c", dest[0]);
//		i++;
//	}
/*	
	while ((buf = read(fd, dest, BUFF_SIZE)))
	{
		if(dest[0] != '\n')
		{
			printf("%c", dest[0]);
		}
		else
		{
			break;
		}
	}
*/
//Read the file upto buff_size or newline, whichever one comes later.	
// Using dest
/*
	while(ft_strchr(dest, '\n') == NULL)
	{
		buf = read(fd, dest, BUFF_SIZE);
		dest[buf] = '\0';
//		printf("%s", dest);
		placeholder = ft_strjoin(placeholder, dest);
	}
	printf("%s", placeholder);
*/
// Using storage

// ✗	Fix this while loop ✗
// Check for newline while joining
	while(ft_strchr(storage, '\n') == NULL)
	{
	//	buf = read(fd, storage, BUFF_SIZE);
	//	storage[buf] = '\0';
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
//		if(placeholder[len] != '\n')
//		{
		placeholder = ft_strjoin(placeholder, storage);
//		}
//		len++;
	}
//	printf("      buf:|%d|\n", buf);
//	len = 0;
	printf("\nLength of placeholder:|%zu|\n", ft_strlen(placeholder));
	printf("Buffer read/placeholder:\n|%s|", placeholder);

// ✓	This is fine	✓ 
	while(placeholder[len] != '\n')
	{
		len++;	
	}
//	printf("\n\nlen of placeholder\n\n|%d|", len);

// ✓	This is fine	✓
	one_line = ft_strsub(placeholder, 0, len);
	printf("\n\n\nPrinting one_line:\n|%s|", one_line);

//	ft_memmove(placeholder, 0, len);
//	printf("\n\n\nPrinting one_line:\n|%s|", placeholder);

// ✓	This is fine	✓
//	ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
	printf("\n\nBefore storage is trimmed:\n|%s|\n", storage);

//	printf("\nExperiment1:\n|%s|\n", storage+len);
//	if (len == BUFF_SIZE)
//		printf("\nExperiment2.1:\n|%s|\n", ft_strsub(placeholder, len-1, BUFF_SIZE));
//	else if (len < BUFF_SIZE)
//		printf("\nExperiment2.2:\n|%s|\n", ft_strsub(placeholder, len, (BUFF_SIZE - len)));
	if(len >= BUFF_SIZE)
	{
		printf("\n\nE2.1:Printing stored characters:\n|%s|", storage);
//		return(storage);
	}
	else if (len < BUFF_SIZE)
	{
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));	///-> Trimming storage
		printf("\n\nE2.2:Printing stored characters:\n|%s|\n", storage);
//		return(storage);
	}

	return(0);

}

