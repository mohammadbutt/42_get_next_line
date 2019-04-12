/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:01:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/12 12:16:31 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **one_line)
{
	static int start;
	int len;
	char placeholder[BUFF_SIZE + 1];
	char *s;
	static char *storage;

		len = 0;
//	if(!start)
//		start = 0;
	if(!storage)
		storage = ft_strnew(0);
//	placeholder = ;

	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, placeholder, BUFF_SIZE);
		placeholder[BUFF_SIZE] = '\0';
		storage = ft_strjoin(storage, placeholder);
	}

	while(storage[len] != '\n')
		len++;	
	len = len - start;
	*one_line = ft_strsub(storage, start, len);
	

	storage[len] = '\0' ;
	s = ft_strdup(&*(storage + len));
//	free(storage);
//	storage = ft_strdup(&(*s));
//	printf("       s:|%s|\n", s);
	printf(" storage:|%s|\n", storage);
	printf("one_line:|%s|\n", *one_line);
	printf("       s:|%s|\n", s);
	printf("   start:|%d|\n", start);
	printf("     len:|%d|\n\n", len);
//	if ((len) < BUFF_SIZE)
//		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
//	printf("\n|%s|\n", storage);
//	start = len + 1;
//	printf("\n|%s|\n", *one_line);
	
	start = len;
//	free(storage);
	if(fd == -1)
		return(-1);
	else if (fd >= 1)
		return(1);
	return(0);
}
int main (void)
{
	int fd;
	char *one_line;
	fd = open("test4.txt", O_RDONLY);

//	printf("%d\n", fd);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	free(one_line);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);

}
