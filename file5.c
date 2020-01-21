/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 04:36:51 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 00:18:38 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux3(const char **format, t_list_type *structure)
{
	if (**format == '.')
		(*format)++;
	if (((**format == 'd' || **format == 'i') &&
	structure->integer == 0) || (**format == 'u' &&
	structure->unsign == 0))
		(*format)++;
	else
	{
		if ((**format == 'd' || **format == 'i') && structure->integer < 0)
			ft_putchar('-');
		print_format(*format, structure);
		(*format)++;
	}
}

void	aux4(const char **format, t_list_type *structure, t_flag *flaag)
{
	if (find(*format, '*') == 1)
		printf_flag(format, flaag, structure);
	else if (condition1(*format) == 1)
		print_c(format, structure);
	else if (condition2(*format, structure) == 1)
		function(format, structure);
	else if (is_format(**format) == 1)
	{
		if ((**format == 'd' || **format == 'i') && structure->integer < 0)
			ft_putchar('-');
		print_format(*format, structure);
		(*format)++;
	}
	else if (condition3(*format) == 1)
		aux3(format, structure);
	else if (is_width(**format) == 1 || **format == '-')
		print_left(format, structure);
}

int		condition4(const char *format, t_list_type *structure, int k, int j)
{
	if (((format[k] == 'd' || format[k] == 'i') && format[j] == '0' &&
		format[j + 1] == '*' && structure->integer == 0)
			|| ((format[k] == 'x' ||
		format[k] == 'X') && format[j] == '0' &&
				format[j + 1] == '*' && structure->unsign == 0))
		return (1);
	else
		return (0);
}

void	aux5(const char *format, char *s, t_list_type *structure)
{
	int	i;

	i = ft_atoi((const char *)s) - types(format, structure);
	if (*(format - ft_strlen(s)) == '0' && find(format, '.') == 0)
	{
		if (negative(format, structure) == 1)
			ft_putchar('-');
		while (i-- > 0)
			ft_putchar('0');
	}
	else if ((*(format - ft_strlen(s)) >= '1' &&
			*(format - ft_strlen(s)) <= '9') ||
			(*(format - ft_strlen(s)) == '0'
			&& find(format, '.') == 1))
	{
		while (i-- > 0)
			ft_putchar(' ');
		if (negative(format, structure) == 1
				&& *(format - ft_strlen(s) - 1) != '-')
			ft_putchar('-');
	}
}

void	aux6(const char **format, char *s)
{
	int	i;

	i = absolue(ft_atoi(s));
	while (i-- > 0)
		ft_putchar(' ');
	while (is_format(**format) == 0)
		(*format)++;
}
