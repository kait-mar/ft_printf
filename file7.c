/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:33:08 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 10:57:28 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm1(const char *format, int i, int test_0, list_type *structure)
{
	i -= 1;
	if (test_0 == 0)
	{
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar('0');
	}
	if (*format == 'c')
		print_format(format, structure);
	else
		ft_putchar('%');
}

void	norm2(const char *format, int i, list_type *structure)
{
	i = absolue(i) - 1;
	if (*format == 'c')
		print_format(format, structure);
	else
		ft_putchar('%');
	while (i-- > 0)
		ft_putchar(' ');
}

int		norm3(const char **format)
{
	char	*str;
	int		i;

	i = 0;
	while (is_width((*format)[i]) == 1)
		i++;
	str = malloc(i + 1);
	i = 0;
	while (is_width(**format) == 1)
	{
		str[i++] = **format;
		(*format)++;
	}
	str[i] = '\0';
	i = ft_atoi(str);
	return (i);
}

void	norm4(const char **format)
{
	if (**format == '-')
		(*format)++;
	while (is_width(**format) == 1)
		(*format)++;
	(*format)++;
}

void	norm5(const char **format, int count, int test_0, list_type *structure)
{
	int	i;

	i = norm3(format) * count;
	if (**format == '.')
		(*format)++;
	if (i >= 0)
		norm1(*format, i, test_0, structure);
	else
		norm2(*format, i, structure);
	norm4(format);
}
