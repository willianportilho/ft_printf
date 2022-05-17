/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:13:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/05/17 22:31:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

static void	write_n(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n < 10)
		write_n(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		write_n(n % 10);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	i = 0;
	len_s = ft_strlen((char *)s);
	if ((len_s - start) < len)
		len = (ft_strlen((char *)s) - start);
	if (start > len_s)
		len = 0;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while ((i < len) && (s[start != '\0']))
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	va_start(ap, str);
	while (ptr[i])
	{
		if (((ptr[i] >= 0) && (ptr[i] <= 255)) && (ptr[i] != 37))
		{
			ft_putchar(ptr[i]);
			i++;
		}
		if ((ptr[i] == '%') && ((ptr[i + 1] == 'd') || (ptr[i + 1] == 'i')))
		{
			ft_putnbr(va_arg(ap, int));
			i = i + 2;
		}
		if ((ptr[i] == '%') && (ptr[i + 1] == 'c'))
		{
			ft_putchar(va_arg(ap, int));
			i = i + 2;
		}
		if ((ptr[i] == '%') && (ptr[i + 1] == 's'))
		{
			ft_putstr(va_arg(ap, char *));
			i = i + 2;
		}
		if ((ptr[i] == '%') && (ptr[i + 1] == '%'))
		{
			ft_putchar(ptr[i + 1]);
			i = i + 2;
		}
	}
	va_end(ap);
	return (i);
}
