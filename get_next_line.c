/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:17:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/21 10:12:48 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			len;
	char		placeholder[BUFF_SIZE + 1];
	char		*temp;
	static char *s[FD_MAX];
	int			bytes_read;

	len = 0;
	if (fd == -1 || fd > FD_MAX || (read(fd, placeholder, 0) == -1))
		return (-1);
	(s[fd] == NULL) && (s[fd] = ft_strnew(1));
	while ((ft_strchr(s[fd], '\n') == NULL) || (ft_strchr(s[fd], '\0') == NULL))
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if (bytes_read == 0 && *s[fd] != '\0')
		{
			temp = s[fd];
			s[fd] = ft_strjoin(temp, "\n");
			ft_memdel((void **)&temp);
		}
		if (bytes_read == 0)
			break ;
		placeholder[bytes_read] = '\0';
		temp = s[fd];
		s[fd] = ft_strjoin(temp, placeholder);
		ft_memdel((void **)&temp);
	}
	if (*s[fd] == '\0')
		return (0);
	while (s[fd][len] != '\0' && s[fd][len] != '\n')
		len++;
	*line = ft_strsub(s[fd], 0, len);
	temp = ft_strdup(&*(s[fd] + len + 1));
	ft_memdel((void **)&s[fd]);
	s[fd] = ft_strdup(temp);
	ft_memdel((void **)&temp);
	return (1);
}
/*
int main (void)
{
	int fd;
	int ret;
	char *one_line;
	ret = 0;
	fd = 0;
	fd = open("test7_3.txt", O_RDONLY);
		while ((ret = get_next_line(fd, &one_line) > 0))
		{
			printf("fd should be 1:|%d|\n", ret);
			printf("This is the line:|%s|\n\n", one_line);
			free(one_line);
		}
}
*/
/*
// Command line
int main (int argc, char **argv)
{
	int fd;
	int ret;
	char *one_line;
	ret = 0;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
		while((ret = get_next_line(fd, &one_line) > 0))
		{
			printf("fd should be 1:|%d|\n", ret);
			printf("This is the line:|%s|\n\n", one_line);
			free(one_line);
		}
}
*/
/*
// multiple files
int main (void)
{
	int fd1;
	int ret1;
	char *one_line1;
	int fd2;
	int ret2;
	char *one_line2;
	fd1 = 0;
	fd2 = 0;
	ret1 = 0;
	ret2 = 0;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while((ret1 = get_next_line(fd1, &one_line1) > 0) && (ret2 = get_next_line(fd2, &one_line2) > 0))
	{
//		printf("|%d|", ret1);
		printf("%s\n", one_line1);
		free(one_line1);
//		printf("|%d|", ret2);
		printf("%s\n\n", one_line2);
		free(one_line2);
	}
}
*/
