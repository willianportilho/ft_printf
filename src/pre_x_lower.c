/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_x_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:16:16 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:38:19 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	pre_x_lower(unsigned int n, int *i, int *len)
{
	unsigned int	cp;

	cp = n;
	*len = *len + 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			*len = *len + 1;
		}
	}
	*i = *i + 2;
	ft_uitohex(n);
}
