/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:17:35 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/13 19:06:21 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include "./libft/libft.h"

int	get_next_line(const int fd, char **one_line);

#define BUFF_SIZE 20

//Delete below
//#define FD_MAX 1023
//Delete above

#endif
