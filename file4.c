/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 04:16:03 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 11:33:31 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		condition1(const char *format)
{
	return (find(format, '.') == 1 &&
			(format[indice(format, '.') + 1] == 'c' ||
				format[indice(format, '.') + 1] == '%'));
}

int		condition2(const char *format, list_type *structure)
{
	if (find(format, '.') == 1 &&
			(is_width(format[indice(format, '.') + 1]) == 1 ||
				format[indice(format, '.') + 1] == '-'
		|| format[indice(format, '.') + 1] == 's' ||
		((format[indice(format, '.') + 1] == 'p' ||
				format[indice(format, '.') + 1] == 'x' ||
				format[indice(format, '.') + 1] == 'X')
			&& structure->unsign == 0)))
		return (1);
	else
		return (0);
}

void	auxilliaire1(const char **format)
{
	int	i;

	while (**format != '%' && **format != '\0')
	{
		ft_putchar(**format);
		(*format)++;
	}
	i = 0;
	while (**format == '%' && *(*format + 1) == '%')
	{
		(*format)++;
		i++;
	}
	i++;
	aux2(format, i);
}

void	aux2(const char **format, int i)
{
	if (i % 2 != 0)
	{
		i /= 2;
		while (i-- > 0)
			ft_putchar('%');
	}
	else
	{
		i /= 2;
		while (i-- > 0)
			ft_putchar('%');
		(*format)++;
		while (**format != '%' && **format != '\0')
		{
			ft_putchar(**format);
			(*format)++;
		}
	}
}

int		condition3(const char *format)
{
	return ((*format == '.' && (*(format + 1) == 'd' || *(format + 1) == 'x' ||
					*(format + 1) == 'X' || *(format + 1) == 'p' ||
					*(format + 1) == 'i')));
}
