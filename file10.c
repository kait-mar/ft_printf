/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:20:06 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:32:00 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help1(const char **format, t_list_type *structure)
{
	while (**format == '0' || **format == '-')
		(*format)++;
	norm5(format, -1, 0, structure);
}

int		cond10(const char **format)
{
	int	k;

	k = 0;
	while (is_format((*format)[k]) == 0)
		k++;
	return (find(*format, '.') == 0 &&
			find(*format, '0') == 1
			&& find(*format, '-') == 1
			&& (*format)[k] == '%');
}

int		condition_mod(const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && is_format(format[i]) == 0)
		i++;
	return (find(format, '0') == 1 &&
			find(format, '-') == 1
			&& find(format, '.') == 0
			&& format[i] == '%');
}

void	normin(const char **format, t_list_type *structure)
{
	while (**format == '-' && **format != '\0')
		(*format)++;
	if (negative(*format, structure) == 1)
		ft_putchar('-');
	print_format(*format, structure);
	print_right_left(format, structure);
	if (find(*format, '.') == 1)
		(*format)++;
	(*format)++;
}

int		skip(const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	while (format[i] != '\0' && format[i] == '%' && format[i + 1] == '%')
		i++;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	return (i);
}
