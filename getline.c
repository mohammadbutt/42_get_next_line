/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:21:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/30 15:15:18 by mbutt            ###   ########.fr       */
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
	FILE *source;
	char *dest = NULL;
	size_t len = 0;
	ssize_t read_this;

	source = fopen("test.txt", "r");

//	if (source == NULL)
//		exit(EXIT_FAILURE);

	while ((read_this = getline(&dest, &len, source)) != -1)
	{
		printf("Retrieved line of length %zu :\n", read_this);
//		printf("Len is %zu\n", len);
		printf("%s", dest);
	}

//	free(dest);
//	exit(EXIT_FAILURE);
}
