/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:17:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/18 11:20:49 by mbutt            ###   ########.fr       */
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
	
	if (fd == -1 || (read(fd, placeholder, 0) == -1))
		return (-1);

	if (storage == NULL)
		(storage = ft_strnew(0));
	while(ft_strchr(storage, '\n') == NULL)
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if (bytes_read == 0)
			break;
		placeholder[bytes_read] = '\0';
// -- Passes basic test

		temp = storage;
		storage = ft_strjoin(temp, placeholder);
		ft_memdel((void **)&temp);
// -- passes basic test
// -- Below works fine
/*
		temp = ft_strdup(storage);
		free(storage);
		storage = ft_strjoin(temp, placeholder);
		free(temp);
*/
// -- above works fine
	}
	if(*storage == '\0')
		return(0);
	while ((storage[len] != '\0') && (storage[len] != '\n'))
		len++;
	*one_line = ft_strsub(storage, 0, len);
	storage[len] = '\0';
	temp = ft_strdup(&*(storage + len + 1));
//	free(storage);
	ft_memdel((void **)&storage);
	storage = ft_strdup(temp);
//	free(temp);
	ft_memdel((void **)&temp);
	return(1);
}

int main (void)
{
	int fd;
	char *one_line;
	int ret;
	char buff[4];
	ret = -1;
	one_line = NULL;
	fd = open("test1.txt", O_RDONLY);

	printf("fd:|%d|\n", fd);
	printf("When file is open|%zd|\n",read(fd, buff, 4));
	printf("this is fd when file is open: |%d|\n", fd);

	close(fd);
	printf("fd:|%d|\n", fd);
	printf("this is fd after file is closed:|%d|\n", fd);
	printf("When file is closed:|%zd|\n",read(fd, buff, 4));


	while((ret = get_next_line(6, &one_line) > 0))
	{
		printf("fd should be 1:|%d|\n", ret);
		printf("|%s|\n\n", one_line);
		free(one_line);
	}

//	printf("-99|%d|\n", get_next_line(-99, NULL));
//	printf("-1|%d|\n", get_next_line(-1, NULL));
//	printf("-10000|%d|\n", get_next_line(-10000, NULL));
//	iprintf("0|%d|\n", get_next_line(0, NULL));
//	printf("1|%d|\n", get_next_line(1, NULL));
//	printf("2|%d|\n", get_next_line(2, NULL));
//	printf("3|%d|\n", get_next_line(3, NULL));
//	printf("99|%d|\n", get_next_line(99, NULL));
//	printf("-99|%d|\n", get_next_line(-99, &one_line));

//	printf("%d\n", get_next_line(-1, &one_line));
//	printf("%d\n", get_next_line(-10000, &one_line));
//	printf("%d\n", get_next_line(-99, NULL));
//	printf("%d\n", get_next_line(-99, NULL));
//	printf("%d\n", get_next_line(-99, NULL));

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
