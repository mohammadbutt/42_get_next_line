/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:54:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/29 13:51:38 by mbutt            ###   ########.fr       */
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
// Code taken from wikipedia/Static_variable
//void func() {
//	static	int x = 0;
//	/* x is initialized only once across five calls of func() and
//	  the variable will get incremented five
//	  times after these calls. The final value of x will be 5. */
//	x++;
//	printf("%d\n", x); // outputs the value of x
//}
/*
int main() { //int argc, char *argv[] inside the main is optional in the particular program
	func(); // prints 1
	func(); // prints 2
	func(); // prints 3
	func(); // prints 4
	func(); // prints 5
	return 0;
}
*/
int main (void)
{
//---------------------------------------------------------------------------
//Following thenewboston youtube tutorial
// declare variable that will hold the contents of th file
	FILE * fpointer;

// opens the file and stores it in fpointer.	
	fpointer = fopen("test.txt", "r");

	char singleLine[150];

	while(!feof(fpointer))
	{
		fgets(singleLine, 150, fpointer); // we are trying tp replicate this fgets
//		getline(singleLine, 150, fpointer);
//		puts(singleLine);
		printf("%s",singleLine); // For fgets
	}
	fclose(fpointer);
	printf("---------------------------------------------------------------\n");
//--------------------------------------------------------------------------
//Following Bluefever software youtube tutorial to see how while loops work differently

	FILE *pToFile = fopen("test.txt", "r");
	int line = 0;
	char input[3];
	while (fgets(input, 3, pToFile)) // we are trying to replicate this fgets.
//	while(getline(input, 512,pToFile))
	{
		line++;
		printf("%s",input);
//		puts(input);
	}
	fclose(pToFile);
	return(0);
}
