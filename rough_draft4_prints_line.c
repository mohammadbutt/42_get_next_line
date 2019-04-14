/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:01:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/13 20:12:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **one_line)
{
//	static int start;
	int len;
	char placeholder[BUFF_SIZE + 1];
	char *s;
	static char *storage;
	int i;

	len = 0;
	i = 0;
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
//	len = 0;
	
//	while (s[i] != c && s[i] != '\0' && (len++ >= 0))
//			i++;

	while (storage[len] != '\n')
	{
//		if (storage[i] != '\n')
//		{
//			i++;
			len++;
//		}
//		else if(storage[i] == '\n')
//			i++;
	}

//	while(storage[len] != '\n')
//	{
//		len++;
//		i++;
//	}
//	len = len - start;
	*one_line = ft_strsub(storage, 0, len);
	

	printf("       i:|%d|\n", i);
//	printf("   i-len:|%d|\n", (i - len));
	printf("     len:|%d|\n", len);
	storage[len] = '\0' ;
	s = ft_strdup(&*(storage + len + 1));
//	s[ft_strlen(s)] = '\0';
	printf("       s:|%s|\n", s);
	printf(" storage:|%s|\n", storage);
	free(storage);
	storage = ft_strdup(s);
	free(s);
//	printf("       s:|%s|\n", s);
//	printf(" storage:|%s|\n", storage);
//	printf("storage + len + 1:|%s|\n", (storage+len+1));
	printf("one_line:|%s|\n\n\n", *one_line);
//	printf("       s:|%s|\n\n", s);
//	if ((len) < BUFF_SIZE)
//		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
//	printf("\n|%s|\n", storage);
//	start = len + 1;
//	printf("\n|%s|\n", *one_line);
	
//	start = len + start;
//	free(storage);
//	len = 0;
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
	fd = open("test3.txt", O_RDONLY);
	

	int i = 8;

//	printf("%d\n", fd);
//	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
//	free(one_line);
//	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
//	get_next_line(fd, &one_line);
///	printf("%s\n", one_line);
//	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
//	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
	while(get_next_line(fd, &one_line) && i)
	{
		i--;
	}

}

