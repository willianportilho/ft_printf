/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:42:45 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:41:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_nbr(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
		print_nbr(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		print_nbr(n % 10);
	}
}
