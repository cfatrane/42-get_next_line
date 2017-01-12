/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:53:46 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/02 20:08:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	c;

	i = 128;
	while (i > 0)
	{
		if (octet < i)
		{
			c = '0';
			write(1, &c, 1);
			i /= 2;
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - i;
			i /= 2;
		}
	}
}
