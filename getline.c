#include <stdio.h>
#include <stdlib.h>
int main (void)
{
/*
ssize_t getline(char **dest, size_t *buf, FILE *stream);
*/
	FILE *source;
	char *dest = NULL;
	size_t len = 0;
	ssize_t return_of_getline;
	int 	ret;

	source = fopen("tests/test4.txt", "r");

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

	while((ret = getline(&dest, &len, source)))
	{
		if (ret > 0)
		{
			printf("|%s|\n", dest);
		}
		if ()
	}

	return(0);
}
