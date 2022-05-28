/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:45:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:40:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_nbr_uns(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_putnbr_uns(unsigned int n)
{
	if (n < 10)
		print_nbr_uns(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		print_nbr_uns(n % 10);
	}
}
