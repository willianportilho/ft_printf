/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:50:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:38:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	pre_p(size_t n, int *i, int *len)
{
	size_t	cp;

	cp = n;
	if (n == 0)
	{
		ft_putstr("(nil)");
		*len = *len + 5;
		*i = *i + 2;
		return ;
	}
	*len = *len + 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			*len = *len + 1;
		}
	}
	*len = *len + 2;
	*i = *i + 2;
	ft_uitohex_p(n);
}
