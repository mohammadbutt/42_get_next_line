/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:19:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/14 21:16:43 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **one_line)
{
	int			len;
	char		placeholder[BUFF_SIZE + 1];
	char		*s;
	static char *storage;
	int			buf;

	len = 0;
	if (fd == -1)
		return (-1);
	if(storage == NULL)
		(storage = ft_strnew(0));
	while (ft_strchr(storage, '\n') == NULL)
	{
		buf = read(fd, placeholder, BUFF_SIZE);
		placeholder[buf] = '\0';
		storage = ft_strjoin(storage, placeholder);

// adding below lines		
//		s = ft_strdup(&*(storage));
//		free(storage);
//		storage = ft_strdup(s);
//		free(s);
// adding above lines
		if (buf == 0)
			return (0);
	}
	while (storage[len] != '\n')
		len++;
	*one_line = ft_strsub(storage, 0, len);
	storage[len] = '\0';
	s = ft_strdup(&*(storage + len + 1));
	free(storage);
	storage = ft_strdup(s);
	free(s);
	free(*one_line);
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
	fd = open("test2.txt", O_RDONLY);
	while(get_next_line(fd, &one_line) > 0)
		printf("%s\n", one_line);

	while(1)
	{
	}
	return(0);
}

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
