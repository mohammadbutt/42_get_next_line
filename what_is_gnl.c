

#include "get_next_line.h"

/*
*	Below functions are not mine. I just created the main to understand what the output is supposed to look like.
*/
char	*chop_line(char **string)
{
	char	*new;
	int		length;
	int		i;

	length = 0;
	i = -1;
	while ((*string)[length] != '\0' && (*string)[length] != '\n')
		length++;
	if (!(new = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	while (++i < length)
		new[i] = (*string)[i];
	new[i] = '\0';
	i = 0;
	length++;
	if ((*string)[length - 1] == '\n')
	{
		while ((*string)[length] != '\0')
			(*string)[i++] = (*string)[length++];
	}
	(*string)[i] = '\0';
	return (new);
}

int		read_file(const int fd, char **fd_store, int *ret)
{
	char			buffer[BUFF_SIZE + 1];
	char			*hold;

	while (!(ft_strchr(*fd_store, '\n')) &&
			(*ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[*ret] = '\0';
		hold = *fd_store;
		if (!(*fd_store = ft_strjoin(*fd_store, buffer)))
			return (0);
		free(hold);
	}
	if (*ret == -1)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*fd_store[FD_MAX + 1];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!(fd_store[fd]))
		fd_store[fd] = ft_strnew(1);
	if (!(fd_store[fd]) || !(read_file(fd, &(fd_store[fd]), &ret)))
		return (-1);
	if (fd_store[fd][0] == '\0' && ret == 0)
		return (0);
	if (!(*line = chop_line(&(fd_store[fd]))))
		return (-1);
	return (1);
}

int main (void)
{
//	FILE *source;
//	char *dest = NULL;
//	size_t len = 0;
	ssize_t return_of_gnl;
	int fd1; //Create 1 function to return -1, 0, 1 if the file is read correctly.
	int fd2;

	char *line1;// = NULL; Create a second function that will store the line in this placeholder.
	char *line1_1;// = NULL;


//	source = fopen("test1.txt", "r");
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("nofile.txt", O_RDONLY);

//Reads the whole file in a while loop
/*	
	while (get_next_line(fd1, &line1))
	{
		printf("%s\n", line1);
	}
*/

//Prints one line at a time with
// Returns  1 if not at the end.
// Returns  0 if line is at the end.
// Returns -1 if line is not read succefuly.
	printf("If a file is read succesfully, get_next_line returns 1\n");
	printf("%d\n", get_next_line(fd1, &line1));
	printf("%s\n\n", line1);


//	printf("It doesnt not matter what &line is. Is &line just a placeholder?\n");
//	printf("%d\n", get_next_line(fd1, &line1_1));
//	printf("%s\n\n", line1_1);


	printf("If a file is not read succesfully, get_next_line returns -1\n");
	printf("%d\n", get_next_line(fd2, &line1_1));
	printf("%s\n", line1_1);


	return(0);
}
/*
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
	while ((bytes_read = read(fd, &buffer, BUFF_SIZE - 1)) > 0)
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
	fd = open("hello.txt", O_RDONLY);
	printf("%d\n", fd);
	while (get_next_line(fd, &ptr) > 0)
	{
		printf("[%s]\n", ptr);
		ft_strdel(&ptr);
	}
	return (0);
}
*/
