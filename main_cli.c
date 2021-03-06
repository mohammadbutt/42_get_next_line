/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:57:12 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/22 18:43:07 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This main allows the user to enter a file from command line interface
*/

#include "get_next_line.h"

int main (int argc, char **argv)
{
	int fd1;
	int ret1;
	char *one_line;
	fd1= open(argv[1], O_RDONLY);

	if(argc == 2)
	{
		while((ret1 = get_next_line(fd1, &one_line)))
		{
			if (ret1 > 0)
			{
				printf("|%d||%s|\n", ret1, one_line);
				free(one_line);
			}
			if (ret1 == -1)
//			{
//				printf("|%d|File does not exist\n\n", ret1);
				break;
//			}
		}
		ret1 = get_next_line(fd1, &one_line);
		printf("|%d||%s|\n\n", ret1, one_line);
	}
}
