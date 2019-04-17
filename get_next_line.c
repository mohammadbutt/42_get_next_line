/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:17:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/17 15:30:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **one_line)
{
	int len;
	char placeholder[BUFF_SIZE + 1];
	char *temp;
	static char *storage;
	int bytes_read;

	len = 0;

	if (fd < 0 || read(fd, placeholder, 0) < 0)
		return (-1);
	if (storage == NULL)
		(storage = ft_strnew(0));
	
	while(ft_strchr(storage, '\n') == NULL)
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if (bytes_read == 0)
			break;
		placeholder[bytes_read] = '\0';
		temp = storage;

		storage = ft_strjoin(temp, placeholder);
//		free(storage);
//		storage = temp;
		free(temp);
//		printf("storage in while:|%s|\n", storage);
//		printf("placeholder in while:|%s|", placeholder);
	}

	if(*storage == '\0')
		return(0);
//	while ((storage[len] != '\0') && storage[len] != '\n')
	while ((storage[len] != '\0') && (storage[len] != '\n'))
		len++;

//	len--;
//	printf("len:|%d|\n",len);
//	printf("storage:|%s|\n", storage);
//	if(len == 0 && storage[len] == '\0' && storage[len] != '\n')
//		return(0);
	*one_line = ft_strsub(storage, 0, len);
//	printf("one_line in function:|%s|\n", *one_line);
	storage[len] = '\0';
	
	temp = ft_strdup(&*(storage + len + 1));
	storage = temp;
	return(1);
}

int main (void)
{
	int fd;
	char *one_line;
	int ret;
	fd = open("test1.txt", O_RDONLY);

	while((ret = get_next_line(fd, &one_line) > 0))
	{
		printf("fd should be 1:|%d|\n", ret);
		printf("|%s|\n\n", one_line);
		free(one_line);
	}

//	printf("fd should be 0:|%d|\n", get_next_line(fd, &one_line));
//	printf("one_line:|%s|\n", one_line);
//	printf("fd should be 0:|%d|\n", get_next_line(fd, &one_line));
//	printf("one_line:|%s|\n", one_line);



//	if(ft_strcmp(one_line, "123") == 0)
//		printf("OK");
//	else
//		printf("Error");

//	printf("fd should be 0:|%d|\n", get_next_line(fd, &one_line));
//	printf("one_line:|%s|\n\n", one_line);
}

/*
int main (int argc, char **argv)
{
	int fd;
	char *one_line;
	fd = 1;
	
//	fd = open("test123.txt", O_RDONLY);
	write(fd, "123", 3);

	close(fd);

	get_next_line(0, &one_line);


//	while (argv[1])
//	{
		if(strcmp("123", one_line) == 0)
		{
			printf("OK");
			return(0);
		}
		else
		{
			printf("Error");
			return(0);
		}
			
//	}
	return(0);
}
*/
