/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_wo_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 12:45:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/21 12:46:40 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
}i
