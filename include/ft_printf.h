/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:45:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/28 04:44:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c);
void	ft_putnbr_uns(unsigned int n);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_uitohex_p(size_t n);
void	ft_uitohex_up(unsigned int n);
void	ft_uitohex(unsigned int n);
void	pre_char(int n, int *i, int *len);
void	pre_nbr_uns(unsigned int n, int *i, int *len);
void	pre_nbr(int n, int *i, int *len);
void	pre_p(size_t n, int *i, int *len);
void	pre_str(char *s, int *i, int *len);
void	pre_x_lower(unsigned int n, int *i, int *len);
void	pre_x_upper(unsigned int n, int *i, int *len);

#endif