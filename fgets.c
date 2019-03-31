/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgets.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:52:04 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/29 21:03:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** Description - fgets copies the content from stream onto str. In other words,
** copies content from source to destination specified by size.
** Prototype - char	*fgets(char *dest, int size, FILE *source).
** Return Value - Returns a pointer to the string.
** Functions that are like fgets - strcpy, and strncpy
*/

//thenewboston tutorial

int main (void)
{
	FILE *source;
	char dest[150];

	source = fopen("test.txt", "r");
	
	while(!feof(source))
	{
		fgets(dest, 150, source);
		printf("%s",dest);
	//	dest[0] = '\0';
	}
	

	fclose(source);
	return(0);
}

//Some other tutorial
/*
int main (void)
{
	FILE *source;
	char dest[150];
	int line;

	source =fopen("test.txt", "r");
	line  = 0;

	while(fgets(dest, 150, source))
	{
	//	line++;
		printf("%s", dest);
		line++;
	}
	fclose(source);
	return(0);
}
*/
