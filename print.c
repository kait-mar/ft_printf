/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:05:21 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 05:30:48 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_flag(const char **format, flag *s_flag, list_type *structure)
{
	construction_string(*format, s_flag, structure);
	while (**format != '\0' && is_format(**format) == 0)
		(*format)++;
	(*format)++;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		n;
	int		r;
	int		k;

	ptr = malloc(count * size);
	if (ptr)
	{
		n = count * size / sizeof(long);
		r = count * size % sizeof(long);
		k = 0;
		while (n--)
			((long *)ptr)[k++] = 0;
		while (r--)
			((char *)ptr)[k * sizeof(long) + r] = 0;
		return (ptr);
	}
	return (NULL);
}

int	print_right_left(const char **format, list_type *structure)
{
	int		i;
	char	*s;
	int		count;

	i = 0;
	count = 0;
	while ((*format)[i] >= '0' && (*format)[i] <= '9')
		i++;
	s = malloc(i + 1);
	i = 0;
	while (is_width(**format) == 1)
		s[i++] = *(*format)++;
	s[i] = '\0';
	if (find(*format, '.') == 1 && ((*format)[indice(*format, '.') + 1] == 'd' || (*format)[indice(*format, '.') + 1] == 'i') && structure->integer == 0)
	{
		count = 1;
		aux6(format, s);
	}
	else
		aux5(*format, s, structure);
	return (count);
}

void	ft_putunsign(unsigned int n)
{
	int				tab[100];
	int				i;
	unsigned int	k;

	if (n == 0)
		ft_putchar('0');
	k = n;
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

flag	*construction_flag(const char *format, va_list list)
{
	flag	*structure;
	int		i;

	i = 0;
	structure = malloc(sizeof(flag));
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (format[i] == '%')
	{
		while (format[i] != '\0' && format[i] != '*')
			i++;
		if (format[i] == '*')
		{	
			structure->integer1 = (int)va_arg(list, int);
			i++;
		}
		if (format[i] == '.' && format[i + 1] == '*')
			structure->integer2 = (int)va_arg(list, int);
	}
	return (structure);
}
