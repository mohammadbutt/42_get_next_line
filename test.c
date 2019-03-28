/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:54:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/28 12:42:41 by mbutt            ###   ########.fr       */
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
/*
int main() {
    FILE * f = fopen( "afile.txt", "r" );
    char line[100];
    int n = 0;
    while( fgets( line, 100, f ) != NULL ) {
        printf( "%d %s", ++n, line );
    }
    fclose( f );
}
*/
void func() {
	static	int x = 0;
	/* x is initialized only once across five calls of func() and
	  the variable will get incremented five
	  times after these calls. The final value of x will be 5. */
	x++;
	printf("%d\n", x); // outputs the value of x
}

int main() { //int argc, char *argv[] inside the main is optional in the particular program
	func(); // prints 1
	func(); // prints 2
	func(); // prints 3
	func(); // prints 4
	func(); // prints 5
	return 0;
}
