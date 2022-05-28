/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:49:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:38:17 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	pre_str(char *s, int *i, int *len)
{
	int	len_s;

	len_s = 0;
	*i = *i + 2;
	if (!s)
	{
		ft_putstr("(null)");
		*len = *len + 6;
		return ;
	}
	while (s[len_s])
		len_s++;
	*len = *len + len_s;
	ft_putstr(s);
}
