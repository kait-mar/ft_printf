/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 04:38:52 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:31:03 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cond11(const char **format, t_list_type *structure)
{
	return (find(*format, '.') == 1 &&
			(((*format)[indice(*format, '.') + 1] == 'd'
			|| (*format)[indice(*format, '.') + 1] == 'i')
			&& structure->integer == 0));
}

int		is_width(char c)
{
	return (c >= '0' && c <= '9');
}

void	help_struct(const char *format, t_list_type *structure,
		int i, va_list list)
{
	if (format[i] == 'd' || format[i] == 'i')
		structure->integer = (int)va_arg(list, int);
	else if (format[i] == 'x' || format[i] == 'X')
		structure->unsign = (unsigned int)va_arg(list, unsigned int);
	else if (format[i] == 'u')
		structure->unsign = (int)va_arg(list, int);
	else if (format[i] == 'c')
		structure->car = (char)va_arg(list, int);
	else if (format[i] == '%')
		structure->car = '%';
	else if (format[i] == 'p')
		structure->pointer = (unsigned long long)va_arg(list,
		unsigned long long);
}

int		cond12(const char **format, t_list_type *structure)
{
	return (find(*format, '.') == 1
	&& ((*format)[indice(*format, '.') + 1] == 'd'
	|| (*format)[indice(*format, '.') + 1] == 'i')
	&& structure->integer == 0);
}

void	tab(char **converted)
{
	(*converted)[0] = '0';
	(*converted)[1] = '\0';
}
