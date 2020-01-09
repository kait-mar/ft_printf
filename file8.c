/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:14:27 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 11:02:51 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		condition9(const char **format, list_type *structure, int k)
{
	if ((((((*format)[k] == 'x' || (*format)[k] == 'X') &&
		structure->unsign == 0) || ((*format)[k] == 'p' &&
		structure->pointer == 0)) || (((*format)[k] == 'd' ||
		(*format)[k] == 'i') && structure->integer == 0))
			&& ((*format)[k - 1] == '.' || (*format)[k - 1] == '0'))
		return (1);
	else
		return (0);
}

void	norm6(const char **format, int i, int k)
{
	if ((*format)[k] == 'p')
	{
		if (i < 0)
		{
			i = absolue(i) - 2;
			ft_putchar('0');
			ft_putchar('x');
			while (i-- > 0)
				ft_putchar(' ');
		}
		else
		{
			i = absolue(i) - 2;
			while (i-- > 0)
				ft_putchar(' ');
			ft_putchar('0');
			ft_putchar('x');
		}
	}
	else
		norm7(i);
}

void	norm7(int i)
{
	i = absolue(i);
	while (i-- > 0)
		ft_putchar(' ');
}

void	norm8(const char **format, list_type *structure, int i, int j)
{
	if (structure->integer < 0)
		ft_putchar('-');
	print_format(*format, structure);
	fct2(*format, structure, absolue(i), j);
}

void	norm9(const char **format, list_type *structure, int i)
{
	if (structure->integer < 0)
		ft_putchar('-');
	fct3(*format, structure, i);
}
