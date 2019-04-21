/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:17:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/20 19:49:42 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **one_line)
{
	int len;
	char placeholder[BUFF_SIZE + 1];
	char *temp;
	static char *storage[FD_MAX];
	int bytes_read;

	len = 0;
	
	if (fd == -1 || fd > FD_MAX || (read(fd, placeholder, 0) == -1))
		return (-1);
//Error handler
	if(storage[fd] == NULL)
		storage[fd] = ft_strnew(1);
//	printf("1111111111111111111111111111111111111111111111111111\n");
//	printf("Staring While loop\n");
	while((ft_strchr(storage[fd], '\n') == NULL) || (ft_strchr(storage[fd], '\0') == NULL))
	{
		bytes_read = read(fd, placeholder, BUFF_SIZE);
		if(bytes_read == 0 && *storage[fd] != '\0')
		{
			temp = storage[fd];
			storage[fd] = ft_strjoin(temp, "\0");
			ft_memdel((void **) &temp);
		}
		if (bytes_read == 0)
			break;
		
		placeholder[bytes_read] = '\0';
//		printf("(2)placeholder right after bytes are read:|%s|\n", placeholder);
// -- Passes basic test
//		printf("(3)storage[fd]:|%s|\n", storage[fd]);
		temp = storage[fd];
//		printf("(4)temp:|%s|\n", temp);
		storage[fd] = ft_strjoin(temp, placeholder);
//		printf("(5)storage[fd] after strjoin:|%s|\n", storage[fd]);
//		printf("       (6)temp after strjoin:|%s|\n", temp);
//		printf("(7)placeholder after strjoin:|%s|\n", placeholder);
		ft_memdel((void **)&temp);
//		printf("(7.2)temp after memdel:|%s||\n", temp);

// -- passes basic test
// -- Below fails some tests 
/*
		temp = ft_strdup(storage[fd]);
		ft_memdel((void *)&storage[fd]);
		storage[fd] = ft_strjoin(temp, placeholder);
		ft_memdel((void **)&temp);
*/
// -- above works fine
	}
//	printf("2222222222222222222222222222222222222222222222222222\n");
//	printf("While loop Ended:\n");
	if(*storage[fd] == '\0')
		return(0);
	while (storage[fd][len] != '\0' && storage[fd][len] != '\n')
	{	
//		printf("|%c|", storage[fd][len]);
		len++;
	}
//	printf("(7.3)printing len:|%d|\n", len);
// Add an if statement to return 0 to get BUFF SIZE of 5 to work
/*	
	if (storage[fd][len + 1] == '\0')
		return(0);
*/
//	
//	printf("storage:|%c|\n", storage[fd][len]);
//	printf("len:|%d|\n", len);
	storage[fd][len] = '\0';
//	printf("(7.4)storage right before ft_strsub:|%s|\n", storage[fd]);
	*one_line = ft_strsub(storage[fd], 0, len);
//	storage[fd][len] = '\0';
	temp = ft_strdup(&*(storage[fd] + len + 1));
//	printf("(8)temp:|%s|\n", temp);
	ft_memdel((void **)&storage[fd]);
	storage[fd] = ft_strdup(temp);
//	printf("(9)storage:|%s|\n",storage[fd]);
//	printf("right before return:|%s|\n", storage[fd]);
	ft_memdel((void **)&temp);	
//	printf("(10)temp:|%s|\n", temp);
	
//	printf("333333333333333333333333333333333333333333333\n");
//	printf("Entering main:\n");
	return(1);
}

//#include <string.h>
//#include <stdio.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include "get_next_line.h"

/*
** 2 lines with 8 chars without Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl7_2.txt";
	fd = open(filename, O_RDONLY);
//	printf("3333333333333333333333333333333333333333333333\n");
//	printf("Entered main:\n");
	printf("fd in main:|%d|\n", get_next_line(fd, &line));
	printf("line in main:|%s|\n\n", line);
	printf("fd in main:|%d|\n", get_next_line(fd, &line));
	printf("line in main:|%s|\n\n", line);
	printf("fd in main:|%d|\n", get_next_line(fd, &line));
	printf("line in main:|%s|\n\n", line);
	printf("fd in main:|%d|\n", get_next_line(fd, &line));
	printf("line in main:|%s|\n\n", line);
	printf("fd in main:|%d|\n", get_next_line(fd, &line));
	printf("line in main:|%s|\n\n", line);
	
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
		
	return (0);
}


/*
#include <project.h>

static void simple_string(t_test *test)
{
    char 	*line = NULL;
    
	mt_assert(get_next_line(-99, NULL) == -1);
	mt_assert(get_next_line(-1, NULL) == -1);
	mt_assert(get_next_line(-10000, NULL) == -1);
	mt_assert(get_next_line(1, NULL) == -1);
	mt_assert(get_next_line(99, NULL) == -1);

	mt_assert(get_next_line(-99, &line) == -1);
	mt_assert(get_next_line(-1, &line) == -1);
	mt_assert(get_next_line(-10000, &line) == -1);

	 Not opened fd 
	mt_assert(get_next_line(42, &line) == -1);
}

void	suite_05_test_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
*/
// -- Test case for multiple file descriptor
/*
int				main(void)
{
	char		*line1;
	char		*line2;
	char		*line3;
	int			fd1;
	int			fd2;
	int			fd3;
	int			ret1;
	int			ret2;
	int			ret3;
	char		*filename1;
	char		*filename2;
	int			errors;

//	filename1 = "./srcs/gnl/gnl11_1.txt";
//	filename2 = "./srcs/gnl/gnl11_2.txt";
	filename1 = "gnl11_1.txt";
	filename2 = "gnl11_2.txt";
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = -1;
	if (fd1 > 2 && fd2 > 2)
	{
		errors = 0;
		line1 = NULL;
		line2 = NULL;
		line3 = NULL;

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 1 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 2 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 3 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 4 successful\n");

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
			errors++;
		}
//		
		printf("checkpoint 5 successful\n");

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
			errors++;
		}
//		
		printf("checkpoint 6 successful\n");

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
			errors++;
		}
//		
		printf("checkpoint 7 successful\n");

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
			errors++;
		}
//		
		printf("checkpoint 8 successful\n");

		ret3 = get_next_line(fd3, &line3);
		if (ret3 != -1)
		{
			printf("-> must have returned '-1' with invalid file descriptor\n");
			errors++;
		}
//		
		printf("checkpoint 9 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 10 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 11 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
		{
			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 12 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
		{
			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 13 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
		{
			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 14 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
		{
			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 15 successful\n");

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
			errors++;
		}
	
		printf("checkpoint 16 successful\n");
// -- Segmentation fault -> accessing memory that we dont have access to
		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
			errors++;
		}
//		
		printf("checkpoint 17 successful\n");

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename1);
			errors++;
		}

		printf("checkpoint 18 successful\n");
// -- must have returned '0' at the end of file gnl11_2.txt
		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename2);
			errors++;
		}
//		
		printf("checkpoint 19 successful\n");

		close(fd1);
		close(fd2);
		if (errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening files %s and/or %s\n", filename1, filename2);

//	while(1)
//	{

//	}
//	return (0);
}
*/
/*
int main (void)
{
	int fd;
	char *one_line;
	int ret;
	char buff[4];
	ret = -1;
	one_line = NULL;
	fd = open("test1.txt", O_RDONLY);

	printf("fd:|%d|\n", fd);
	printf("When file is open|%zd|\n",read(fd, buff, 4));
	printf("this is fd when file is open: |%d|\n", fd);

	close(fd);
	printf("fd:|%d|\n", fd);
	printf("this is fd after file is closed:|%d|\n", fd);
	printf("When file is closed:|%zd|\n",read(fd, buff, 4));


	while((ret = get_next_line(6, &one_line) > 0))
	{
		printf("fd should be 1:|%d|\n", ret);
		printf("|%s|\n\n", one_line);
		free(one_line);
	}

//	printf("-99|%d|\n", get_next_line(-99, NULL));
//	printf("-1|%d|\n", get_next_line(-1, NULL));
//	printf("-10000|%d|\n", get_next_line(-10000, NULL));
//	iprintf("0|%d|\n", get_next_line(0, NULL));
//	printf("1|%d|\n", get_next_line(1, NULL));
//	printf("2|%d|\n", get_next_line(2, NULL));
//	printf("3|%d|\n", get_next_line(3, NULL));
//	printf("99|%d|\n", get_next_line(99, NULL));
//	printf("-99|%d|\n", get_next_line(-99, &one_line));

//	printf("%d\n", get_next_line(-1, &one_line));
//	printf("%d\n", get_next_line(-10000, &one_line));
//	printf("%d\n", get_next_line(-99, NULL));
//	printf("%d\n", get_next_line(-99, NULL));
//	printf("%d\n", get_next_line(-99, NULL));

//	printf("fd should be 0:|%d|\n", get_next_line(fd, &one_line));
//	printf("one_line:|%s|\n", one_line);
//	printf("fd should be 0:|%d|\n", get_next_line(fd, &one_line));
//	printf("one_line:|%s|\n", one_line);

}
*/
/*
int main (int argc, char **argv)
{
	int fd;
	char *one_line;
	fd = 1;
	
//	fd = open("test123.txt", O_RDONLY);
	write(fd, "123", 3);

	close(fd);

	get_next_line(0, &one_line);


//	while (argv[1])
//	{
		if(strcmp("123", one_line) == 0)
		{
			printf("OK");
			return(0);
		}
		else
		{
			printf("Error");
			return(0);
		}
			
//	}
	return(0);
}
*/
