/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_nbr_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:04:13 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:38:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	pre_nbr_uns(unsigned int n, int *i, int *len)
{
	unsigned int	cp;

	cp = n;
	*len = *len + 1;
	while (cp > 9)
	{
		cp = cp / 10;
		*len = *len + 1;
	}
	*i = *i + 2;
	ft_putnbr_uns(n);
}
