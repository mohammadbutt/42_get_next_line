#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main (void)
{
/*
ssize_t getline(char **dest, size_t *buf, FILE *stream);
*/
	FILE *fd1;
	char *line = NULL;
	size_t buff_size = 0;
//	ssize_t return_of_getline;
	int 	ret;

	fd1 = fopen("tests/test4.txt", "r");
//	fd1 = open("tests/test4.txt", O_RDONLY);
// Reads the whole file.
/*
	while ((read_this = getline(&dest, &len, source)) != -1)
	{
//		printf("Retrieved line of length %zu :\n", read_this);
		printf("%s", dest);
	}
*/
// Reads one line at a time.
/*	
	return_of_getline = getline(&dest, &len, source);
	printf("Return of getline:|%zu|\n", return_of_getline);
	printf("%s\n\n", dest);

	return_of_getline = getline(&dest, &len, source);
	printf("Return of getline:|%zu|\n", return_of_getline);
	printf("%s\n\n", dest);
*/

	while((ret = getline(&line, &buff_size, fd1)))
	{
		if (ret > 0)
		{
			printf("%s", line);
		}
		else
			break;
	}

	return(0);
}
