/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 09:36:31 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 01:07:54 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		is_format(char c)
{
	if (c == 'u' || c == 'c' || c == 's' || c == 'x' || c == 'X' || c == 'p' ||
		c == 'i' || c == 'p' || c == 'd' || c == '%')
		return (1);
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_list_type	*structure;
	t_flag		*flaag;
	int			test;

	test = 0;
	va_start(list, format);
	g_counter = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			flaag = construction_flag(format, list);
			structure = construction_struct(format, list);
			format++;
			aux4(&format, structure, flaag);
		}
		else
		{
			auxilliaire1(&format);
		}
	}
	va_end(list);
	return (g_counter);
}
