/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:14:36 by cfatrane          #+#    #+#             */
/*   Updated: 2016/11/20 16:58:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	ret = read(fd, buf, BUFF_SIZE);
	ft_strrchr(*line , '\n');
	return (0);
}
