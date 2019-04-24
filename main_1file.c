/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 12:30:49 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/23 21:15:58 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int fd;
	int ret;
	char *one_line;
	fd = open("tests/the_lord_of_the_ring.txt", O_RDONLY);
	while((ret = get_next_line(fd, &one_line)))
	{
		if (ret > 0)
		{
//			printf("return:|%d|", ret);
			printf("|%s|\n", one_line);
			free(one_line);
		}
		if (ret == -1)
		{
			printf("File does not exist");
			break;
		}
	}
}
