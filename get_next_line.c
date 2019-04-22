/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:17:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/22 14:56:59 by mbutt            ###   ########.fr       */
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
