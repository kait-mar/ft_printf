/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:05:21 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 00:36:05 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_flag(const char **format, t_flag *flaag, t_list_type *structure)
{
	construction_string(format, flaag, structure);
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

int		print_right_left(const char **format, t_list_type *structure)
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
	if (cond12(format, structure) == 1)
	{
		count = 1;
		aux6(format, s);
	}
	else
		aux5(*format, s, structure);
	free(s);
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

t_flag	*construction_flag(const char *format, va_list list)
{
	t_flag	*structure;
	int		i;

	structure = malloc(sizeof(t_flag));
	i = skip(format);
	if (format[i] == '%')
	{
		i++;
		if (find((format + i), '*') == 1)
		{
			while (format[i] != '\0' && is_format(format[i]) == 0
				&& format[i] != '*')
				i++;
			if (format[i] == '*')
			{
				structure->integer1 = (int)va_arg(list, int);
				i++;
			}
			if (format[i] == '.' && format[i + 1] == '*')
				structure->integer2 = (int)va_arg(list, int);
		}
	}
	return (structure);
}
