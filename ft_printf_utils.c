/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:56:52 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 12:56:23 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

int	number_length(int n)
{
	int	i;
	int	nb;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	nb = n;
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void	ft_putnbr(long n)
{
	int				tab[100];
	int				i;
	unsigned int	k;

	if (n == 0)
		ft_putchar('0');
	k = n;
	if (n < 0)
		k = -n;
	i = 0;
	while (k != 0)
	{
		tab[i] = k % 10 + '0';
		k = k / 10;
		i++;
	}
	while (i-- > 0)
		ft_putchar(tab[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_counter++;
}

void	print_format(const char *format, list_type *structure)
{
	int		i;
	char	*str;

	i = aux9(format);
	if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(absolue(structure->integer));
	else if (format[i] == 'u')
		ft_putunsign(structure->unsign);
	else if (format[i] == 's')
		ft_putstr(structure->string);
	else if (format[i] == 'c')
		ft_putchar(structure->car);
	else if (format[i] == 'x')
		ft_putstr(dec_to_hexax(structure->unsign));
	else if (format[i] == 'X')
		ft_putstr(dec_to_hexaX(structure->unsign));
	else if (format[i] == 'p')
	{
		str = malloc(3);
		aux8(&str, structure);
		ft_putstr(str);
		//free str
	}
}
