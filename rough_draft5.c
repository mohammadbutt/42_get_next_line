/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:19:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/17 20:52:08 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **one_line)
{
	int			len;
	char		placeholder[BUFF_SIZE + 1];
	char		*temp;
	static char *storage;
	int			bytes_read;
//	int			index;

	len = 0;
//	index = 0;
	if (fd == -1)
		return (-1);
	if(storage == NULL)
		(storage = ft_strnew(1));
//	if(storage != NULL)
//		(free(storage));
//	free(storage);
// ---------BELOW CODE IS USEFUL ----- SPLIT IT INTO TWO IF AND WHILE STATMENTS for \n and %
/*
//	while (ft_strchr(storage, '\n') == NULL)
//	while((ft_strchr(storage, '\0') == NULL) || (ft_strchr(storage, '\n') == NULL))
	while((ft_strchr(storage, '\0') == NULL) || (ft_strchr(storage, '\n') == NULL))
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if (bytes_read == 0)
			return(0);
//		placeholder[bytes_read] = '\0';
		temp = ft_strjoin(storage, placeholder);
		free(storage);
		storage = temp;
		printf("bytes_read:|%d|\n", bytes_read);
		printf("storage:|%s|\n", storage);
		printf("printing bytes_read\n\n\n\n");
//		break;
	}
*/	
//		if((ft_strchr(storage, '\0') == NULL) && (ft_strchr(storage, '\n') == NULL))
//			break;
//		if ((bytes_read == 0) && (storage == NULL) && storage[0] == '\0')
//			return(0);
//		temp = ft_strdup(&*(storage));
//		free(storage);
//		storage = ft_strdup(temp);
////	ft_memdel((void **) &storage);
////	storage = ft_strcpy(storage, temp);
//		free(temp);
//		free(storage);
// adding below lines		
//		s = ft_strdup(&*(storage));
//		free(storage);
//		storage = ft_strdup(s);
//		free(s);
// adding above lines
// -------------- ABOVE IS USEFUL REPLICATING IT INTO SEPERATE IF AND WHILE STATEMENTS


	while(ft_strchr(storage, '\n') == NULL)
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if (bytes_read == 0)
			break;
//			return(0);
		placeholder[bytes_read] = '\0';
		temp = ft_strjoin(storage, placeholder);
		free(storage);
		storage = temp;
//		printf("\nbytes_read:|%d|\n", bytes_read);
//		printf("storage:|%s|\n", storage);
//		printf("printing bytes_read\n\n\n\n");
//		if (bytes_read == 0)
//			break;
//		else if()
//			return(0);
//			break;
//		if(strchr(storage, '\0'))
//			break;
	}


	while ((storage[len] != '\0') && ( storage[len] != '\n'))
		len++;
//	printf("len:|%d|\n", len);
	if(len == 0 && storage[len+1] == '\0')
		return(0);
	*one_line = ft_strsub(storage, 0, len);
//	printf("one_line in function:|%s|", *one_line);
	storage[len] = '\0';
//	free(temp);
	
	temp = ft_strdup(&*(storage + len + 1));
	free(storage);
	storage = temp;
//	free(storage);
//	storage = temp;
//	free(temp);
//	free(temp);
//	storage = ft_memcpy(storage, s, len);	
//	printf("3. memory address of storage:|%p|\n", storage);
//	printf("4. memory address of s:|%p|\n", s);
//	free(s);
//	printf("5. memory address of s:|%p|\n\n", s);
//	free(storage);
	return (1);
}
/*
** //Test 1
**int main (void)
**{
**	int fd;
**	char *one_line;
**	fd = open("test1.txt", O_RDONLY);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**	printf("fd:|%d|		", get_next_line(fd, &one_line));
**	printf("%s\n", one_line);
**}
*/

 // Test 2
int main (void)
{
	int fd;
	char *one_line;
	fd = open("test1.txt", O_RDONLY);
	while(printf("|%d|\n",get_next_line(fd, &one_line)) > 0)
	{
		printf("|%s|\n\n", one_line);
		free(one_line);
	}
}
/*	
	printf("\n\nreturn:|%d|\n",get_next_line(fd, &one_line));
	printf("one_line:|%s|\n\n", one_line);
	printf("-------------------------------------------------");
	printf("\n\nreturn:|%d|\n",get_next_line(fd, &one_line));
	printf("one_line:|%s|\n\n", one_line);
	printf("-------------------------------------------------");
	printf("\n\nreturn should be 0:|%d|\n",get_next_line(fd, &one_line));
	printf("one_line:|%s|\n\n", one_line);
}
*/

/*
 // Test3 for argc and argv
int main(int argc, char **argv)
{
	int fd;
	char *one_line;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &one_line) > 0)
		printf("%s\n", one_line);
	while(1)
	{

	}
	return (0);
}
*/
/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl7_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
				errors++;
			if (count_lines == 3 && strcmp(line, "defghijk") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> should have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> should have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
*/
