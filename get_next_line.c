/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:24:02 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/07 21:51:41 by mbutt            ###   ########.fr       */
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
	char dest[BUFF_SIZE + 1];
	char **final_dest;
	int buf;
	int fd;
	int i;
//	int index;
	char *placeholder;
	placeholder = "";
//	char **new_placeholder;

	i = 0;
//	index = 6;

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
	while(ft_strchr(dest, '\n') == NULL)
	{
		buf = read(fd, dest, BUFF_SIZE);
		dest[buf] = '\0';
//		printf("%s", dest);
		placeholder = ft_strjoin(placeholder, dest);
	}
//	printf("%s", placeholder);
//	printf("%s", ft_strchr(placeholder, '\n'));
	while(placeholder[i] != '\n')
	{
		printf("%c", placeholder[i]);
		i++;
	}
	return(0);
}

