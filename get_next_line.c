/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:01:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/11 20:05:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **one_line)
{
	int start;
	int len;
	char *placeholder;
	static char storage[BUFF_SIZE + 1];

	len = 0;
	start = 0;
	placeholder = "";

	while(ft_strchr(storage, '\n') == NULL)
	{
		read(fd, storage, BUFF_SIZE);
		storage[BUFF_SIZE] = '\0';
		placeholder = ft_strjoin(placeholder, storage);
	}

	while(placeholder[len] != '\n')
		len++;
	len = len - start;
	*one_line = ft_strsub(placeholder, start, len);

	if ((len) < BUFF_SIZE)
		ft_memmove(storage, (storage + len + 1), ft_strlen(storage));
	printf("\n|%s|\n", storage);

	if(fd == -1)
		return(-1);
	else if(fd >= 1)
		return(1);
	return(0);
}

int main (void)
{
	int fd;
	char *one_line;
	fd = open("test3.txt", O_RDONLY);

//	printf("%d\n", fd);
	get_next_line(fd, &one_line);
//	printf("%s\n", one_line);
//	free(one_line);
	get_next_line(fd, &one_line);
//	printf("%s", one_line);

	return(0);
}

