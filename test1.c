/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:55:39 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/07 21:29:07 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int main (void)
 {
	const char *string1 = "testing this thing";
	int c1 = 't';
	const char *string2 = "testing this this ";
	int c2 = 't';
	printf("%s\n", strrchr(string1, c1));
	printf("%s", ft_strrchr(string2, c2));
	return(0);
 }
*/

 int main (void)
 {
	const char *string1 = "this is a test to see";
	int c1 = 'i';
	const char *string2 = "this is a test to see";
	int c2 = 'i';
	const char *string3 = "This is a test.";
	int c3 = ' ';
	printf("%s\n", strchr(string1, c1));
	printf("%s\n", ft_strchr(string2, c2));
//	printf("%s", ft_strchr(string3, c3));
	return(0);
}

