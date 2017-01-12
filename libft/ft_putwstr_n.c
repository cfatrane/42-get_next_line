/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:17:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 15:42:41 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_n(wchar_t *s, int n)
{
	if (s && n != 0)
	{
		while (*s != '\0' && n > 0)
		{
			if (n >= ft_wcharlen(*s))
				ft_putwchar(*s);
			n -= ft_wcharlen(*s);
			s++;
		}
	}
}
