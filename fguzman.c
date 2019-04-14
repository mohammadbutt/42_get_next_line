/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fguzman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:09:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/12 16:44:36 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Below code is not mine
*/

#include "get_next_line.h"
/*
typedef struct s_glist
{
	char *remainder;
}		t_glist;

char *ft_strnjoin(char *s1, char *s2, int code)
{
	char *result;
	
	result = ft_strjoin(s1, s2);

	if(code == 1)
		free(s1);
	if(code == 2)
		free(s2);
	if (code == 3)
	{
		free(s1);
		free(s2);
	}
	return(result);
}

int get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE + 1];
	int bytes_read;
	static char * result;
	char *nl;

	ft_bzero(buffer, BUFF_SIZE);
	bytes_read = 0;

	if(fd < 0 || line == NULL || read(fd, &buffer, 0) < 0)
		return(-1);
	if(result != NULL && ft_strchr(result, '\n') != NULL)
	{
		char *temp;

		temp = ft_strchr(result, '\n');
		temp[0] = '\0';
		*line = ft_strdup(result);
		temp = ft_strdup(&temp[1]);
		free(result);
		result = temp;
		return(1);
	}
	while ((bytes_read = read(fd, &buffer, BUFF_SIZE - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			if (result == NULL)
				result = ft_strdup(buffer);
			else
				result = ft_strnjoin(result, buffer, 1);
		}
		if (result != NULL && ft_strchr(result, '\n') != NULL)
		{
			nl = ft_strchr(result, '\n');
			nl[0] = '\0';
			*line = ft_strdup(result);
			nl = ft_strdup(nl + 1);
			free(result);
			result = nl;
			return(1);
		}
	}
		if (bytes_read == 0 && result && ft_strlen(result) > 0)
		{
			*line = result;
			result = NULL;
			return(1);
		}
		return(0);
}

int	main(void)
{
	char *ptr;
	int fd;
	fd = open("test1.txt", O_RDONLY);
//	printf("%d\n", fd);
//	while (get_next_line(fd, &ptr) > 0)
//	{
//		printf("|%s|\n", ptr);
//		ft_strdel(&ptr);
//	}
	get_next_line(fd, &ptr);
	printf("%s\n", ptr);
	get_next_line(fd, &ptr);
	printf("%s\n", ptr);

	return (0);
}
*/
#include "get_next_line.h"

//typedef struct	s_glist
//{
//	char *remainder;
//} 				t_glist;


char *ft_strnjoin(char *s1, char *s2, int code)
{
	char * result;

	result = ft_strjoin(s1, s2);
	if (code == 1)
		free(s1);
	if (code == 2)
		free (s2);
	if (code == 3)
	{
		free(s1);
		free(s2);
	}
	return (result);
}



int	get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int	bytes_read;
	static char	*result;
	char *nl;

	ft_bzero(buffer, BUFF_SIZE);
	bytes_read = 0;
	if (fd < 0 || line == NULL || read(fd, &buffer, 0) < 0)
	   return (-1);
	if (result != NULL && ft_strchr(result, '\n') != NULL)
	{
		char *temp;

		temp = ft_strchr(result, '\n');
		temp[0] = '\0';
		*line = ft_strdup(result);
		temp = ft_strdup(&temp[1]);
		free(result);
		result = temp;
		return (1);
	}
	while ((bytes_read = read(fd, &buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes_read]  = '\0';
		if (bytes_read > 0)
		{
			if (result == NULL)
				result = ft_strdup(buffer);
			else
				result = ft_strnjoin(result, buffer, 1);
		}
		if (result != NULL && ft_strchr(result, '\n') != NULL)
		{
			nl = ft_strchr(result, '\n');
			nl[0] = '\0';
			*line = ft_strdup(result);
			nl = ft_strdup(nl + 1);
			free(result);
			result = nl;
			return (1);
		}
	}
	if (bytes_read == 0 && result && ft_strlen(result) > 0)
	{
		*line = result;
		result = NULL;
		return (1);
	}
	return (0);
}



int	main(void)
{
	char *ptr;
	int fd;
	fd = open("test1.txt", O_RDONLY);
//	printf("%d\n", fd);
	while (get_next_line(fd, &ptr) > 0)
	{
		printf("|%s|\n", ptr);
		ft_strdel(&ptr);
	}
//	get_next_line(fd, &ptr);
//	printf("%s", ptr);
	return (0);
}
