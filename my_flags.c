/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:33:29 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 01:08:43 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_left(const char **format, t_list_type *structure)
{
	int	count;

	count = 0;
	if (is_width(**format) == 1)
	{
		if (print_right_left(format, structure) == 1)
		{
			(*format)++;
		}
		else
		{
			if (find(*format, '.') == 1)
				(*format)++;
			print_format(*format, structure);
			(*format)++;
		}
	}
	else if (**format == '-')
	{
		if (cond11(format, structure) == 1)
			print_negative(format);
		else
			normin(format, structure);
	}
}

int			types(const char *format, t_list_type *structure)
{
	int	i;

	i = 0;
	while (is_format(format[i]) == 0 && format[i] != '\0')
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		i = number_length(structure->integer);
	else if (format[i] == 'u')
		i = unsign_length(structure->unsign);
	else if (format[i] == 's')
		i = ft_strlen(structure->string);
	else if (format[i] == 'c' || format[i] == '%')
		i++;
	else if (format[i] == 'x')
		i = ft_strlen(dec_to_hexax(structure->unsign));
	else if (format[i] == 'X')
		i = ft_strlen(dec_to_hexaxx(structure->unsign));
	else if (format[i] == 'p')
		i = ft_strlen(dec_to_hexax(structure->pointer)) + 2;
	return (i);
}

int			ft_strlen(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_list_type	*construction_struct(const char *format, va_list list)
{
	t_list_type	*structure;
	int			i;
	char		*str;

	i = 0;
	structure = malloc(sizeof(t_list_type));
	i = skip(format);
	if (format[i] == '%')
	{
		i++;
		while ((is_format(format[i]) == 0
				&& is_flag(format[i]) == 1) && format[i] != '\0')
			i++;
		if (format[i] == 's')
		{
			str = (char *)va_arg(list, char *);
			if (str == NULL)
				str = "(null)";
			structure->string = str;
		}
		else
			help_struct(format, structure, i, list);
	}
	return (structure);
}

int			iflaag(char c)
{
	return ((c == '-') || (c == '*') || (c == '0') || (c == '.'));
}
