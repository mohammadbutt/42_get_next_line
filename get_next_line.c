/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:02:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/10 10:26:10 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int fd;
	int len;
	char *placeholder;
	char storage[BUFF_SIZE + 1];
	char *one_line;

	len = 0;
	placeholder = "";
	one_line = "";

//Opens file
	fd = open("test1.txt", O_RDONLY);
	printf("BUFF_SIZE:|%d|\n", BUFF_SIZE);


//Reads file in a while loop
	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}

	printf("Length of placeholder:|%zu|\n", ft_strlen(placeholder));
	printf("\nBuffer read/placeholder:\n|%s|", placeholder);

//Getting a single line
	while(placeholder[len] != '\n')
		len++;
	one_line = ft_strsub(placeholder, 0, len);
	printf("\n\nBefore storage is trimmed:\n|%s|\n", storage);


//Storing the line in a storage
	if(len >= BUFF_SIZE)
	{
		printf("\n\nE2.1:Printing stored characters:\n|%s|", storage);
	}
	else if (len < BUFF_SIZE)
	{
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
		printf("\n\nE2.2:Printing stored characters:\n|%s|\n", storage);
	}
	printf("\n---------------------------------------------------------\n");
	return(0);
}
