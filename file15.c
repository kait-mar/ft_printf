/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:02:26 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:33:25 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help404(int i, int j)
{
	if (i > 0)
	{
		i = absolue(i) - 2;
		while (i-- > 0)
			ft_putchar(' ');
		ft_putchar('0');
		ft_putchar('x');
	}
	else if (i == 0 && j == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
}

void	help14(const char **format, t_list_type *structure, int i)
{
	if (structure->integer < 0)
		ft_putchar('-');
	fct3(*format, structure, i);
	print_format(*format, structure);
}

void	help15(const char **format, t_list_type *structure, int i, int j)
{
	if (i >= 0)
	{
		fct2(*format, structure, absolue(i), j);
		if (structure->integer < 0)
			ft_putchar('-');
		print_format(*format, structure);
	}
	else
	{
		if (structure->integer < 0)
			ft_putchar('-');
		print_format(*format, structure);
		fct2(*format, structure, absolue(i), j);
	}
}

void	help16(const char **format, t_list_type *structure, int i, int j)
{
	if (structure->integer < 0)
		ft_putchar('-');
	print_format(*format, structure);
	fct2(*format, structure, absolue(i), j);
}

void	help17(const char **format, t_list_type *structure, int i, int j)
{
	if (j > 0 && j < absolue(i) && i < 0)
	{
		fct1(*format, structure, j);
		fct2(*format, structure, absolue(i), j);
	}
	else if (j > 0 && j < i && i > 0)
	{
		fct2(*format, structure, i, j);
		fct1(*format, structure, j);
	}
}
