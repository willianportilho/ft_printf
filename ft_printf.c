/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:13:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/20 01:29:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *index, int *len)
{
	write(1, &c, 1);
	*index = *index + 1;
	*len = *len + 1;
}

void	ft_putchar_c(char c, int *index, int *len)
{
	write(1, &c, 1);
	*index = *index + 2;
	*len = *len + 1;
}

void	ft_putstr(char *s, int *index, int *len)
{
	int	i;

	i = 0;
	*index = *index + 2;
	if (!s)
	{
		(write(1, "(null)", 6));
		*len = *len + 6;
		return ;
	}
	while (s[i])
		write(1, &s[i++], 1);
	*len = *len + ft_strlen(s);
}

static void	write_n(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_putnbr(int n, int *index, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len = *len + 11;
		*index = *index + 2;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		*len = *len + 1;
	}
	if (n < 10)
	{
		write_n(n);
		*index = *index + 2;
		*len = *len + 1;
	}
	if (n > 9)
	{
		*len = *len + 1;
		ft_putnbr(n / 10, index, len);
		write_n(n % 10);
	}
}

void	ft_put_uns_nbr(unsigned int n, int *index, int *len)
{
	if (n < 10)
	{
		write_n(n);
		*index = *index + 2;
		*len = *len + 1;
	}
	if (n > 9)
	{
		*len = *len + 1;
		ft_putnbr(n / 10, index, len);
		write_n(n % 10);
	}
}

void	ft_uitohex_p(size_t n, int *index, int *len)
{
	size_t			cp;
	int				size_memb;
	char			*str;

	cp = n;
	size_memb = 1;
	if (n == 0)
	{
		write (1, "(nil)", 5);
		*len = *len + 5;
		*index = *index + 2;
		return ;
	}
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			size_memb++;
		}
	}
	str = malloc((size_memb * sizeof(char)) + 3);
	str[size_memb] = '\0';
	while (n > 15)
	{
		if ((n % 16) > 9)
			str[--size_memb] = (n % 16) + 87;
		else
			str[--size_memb] = (n % 16) + 48;
		n = n /16;
	}
	if (n > 9)
		str[--size_memb] = n + 87;
	else
		str[--size_memb] = n + 48;
	write(1, "0x", 2);
	*len = *len + 2;
	ft_putstr(str, index, len);
	free (str);
}

void	ft_uitohex(unsigned int n, int *index, int *len)
{
	unsigned int	cp;
	int				size_memb;
	char			*str;

	cp = n;
	size_memb = 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			size_memb++;
		}
	}
	str = malloc((size_memb * sizeof(char)) + 1);
	str[size_memb] = '\0';
	while (n > 15)
	{
		if ((n % 16) > 9)
			str[--size_memb] = (n % 16) + 87;
		else
			str[--size_memb] = (n % 16) + 48;
		n = n /16;
	}
	if (n > 9)
			str[--size_memb] = n + 87;
		else
			str[--size_memb] = n + 48;
	ft_putstr(str, index, len);
	free (str);
}

void	ft_uitohexup(unsigned int n, int *index, int *len)
{
	unsigned int	cp;
	int				size_memb;
	char			*str;

	cp = n;
	size_memb = 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			size_memb++;
		}
	}
	str = malloc(size_memb * sizeof(char) + 1);
	str[size_memb] = '\0';
	while (n > 15)
	{
		if ((n % 16) > 9)
			str[--size_memb] = (n % 16) + 55;
		else
			str[--size_memb] = (n % 16) + 48;
		n = n /16;
	}
	if (n > 9)
			str[--size_memb] = n + 55;
		else
			str[--size_memb] = n + 48;
	ft_putstr(str, index, len);
	free (str);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				index;
	int				len;
	unsigned char	*ptr;

	index = 0;
	len = 0;
	ptr = (unsigned char *)str;
	va_start(ap, str);
	while (ptr[index])
	{
		if (ptr[index] != 37)
			ft_putchar(ptr[index], &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == '%'))
			ft_putchar(ptr[++index], &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 'c'))
			ft_putchar_c(va_arg(ap, int), &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 's'))
			ft_putstr(va_arg(ap, char *), &index, &len);
		if ((ptr[index] == '%') && ((ptr[index + 1] == 'd')
				|| (ptr[index + 1] == 'i')))
			ft_putnbr(va_arg(ap, int), &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 'u'))
			ft_put_uns_nbr(va_arg(ap, unsigned int), &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 'x'))
			ft_uitohex(va_arg(ap, unsigned int), &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 'X'))
			ft_uitohexup(va_arg(ap, unsigned int), &index, &len);
		if ((ptr[index] == '%') && (ptr[index + 1] == 'p'))
			ft_uitohex_p(va_arg(ap, size_t), &index, &len);
	}
	va_end(ap);
	return (len);
}
