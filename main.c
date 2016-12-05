/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:30:28 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/03 19:46:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)argc;
	char *line;
	int fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	close (fd);
	int fd2 = open(argv[1], O_RDONLY);
	while (get_next_line(fd2, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
