/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:54:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/27 15:32:33 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
/*
int main()
{
	char c = 26;
	printf("line 1");
	printf("%c",c);
	printf("line 2\n");
}
*/
/*
int main() {
    int c;
    while( (c = getchar()) != EOF ) {
        putchar( c );
    }
}
*/
#include <stdio.h>
/* -- This gives segmentation fault
int main() {
    FILE * f = fopen( "afile.txt", "r" );
    char line[100];
    int n = 0;
    while( ! feof( f ) ) {
        fgets( line, 100, f );
        printf( "%d %s", ++n, line );
    }
    fclose( f );
}
*/
int main() {
    FILE * f = fopen( "afile.txt", "r" );
    char line[100];
    int n = 0;
    while( fgets( line, 100, f ) != NULL ) {
        printf( "%d %s", ++n, line );
    }
    fclose( f );
}
