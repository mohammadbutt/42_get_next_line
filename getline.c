/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:21:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/08 13:11:32 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Reads an entire line from stream, storing the address of the
** buffer containing the text into *linep.
** Return Value - Returns the number of characters read.
** Return Value - Also returns the content/ characters that were copped from
** source to destination.
** Prototype1 - ssize_t getline(char **linep, size_t *n, FILE *stream);
** Prototype2 - ssize_t getline(char **dest, size_t *len, FILE *source);
*/

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

	source = fopen("test1.txt", "r");

// Reads the whole file.
/*
	while ((read_this = getline(&dest, &len, source)) != -1)
	{
//		printf("Retrieved line of length %zu :\n", read_this);
		printf("%s", dest);
	}

*/
// Reads one line at a time.
	return_of_getline = getline(&dest, &len, source);
	printf("Return of getline:|%zu|\n", return_of_getline);
	printf("%s", dest);

	return(0);
}
