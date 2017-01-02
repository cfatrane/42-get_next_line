/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:36:51 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/29 14:44:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "get_next_line.h"
int main(int argc, char **argv)
{
	int     fd;
	int i;
	char    *line1;
	line1 = "";
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		while (i < 49)
		{
		get_next_line(fd, &line1);
		printf("%s\n", line1);
		i++;
		}/*
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		printf("%s", line1);*/
	}
	else
		printf("usage: please select one file");
	return (0);
}
