/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:37:42 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:31:46 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fct4(const char **format, t_list_type *structure, int i, int j)
{
	fct2(*format, structure, i, j);
	if (structure->integer < 0)
		ft_putchar('-');
}

void	fct5(const char **format, t_list_type *structure, int i, int j)
{
	if (j > 0 && j >= absolue(i))
		fct1(*format, structure, j);
	else if (j > 0 && j < absolue(i) && i < 0)
	{
		fct1(*format, structure, j);
		fct2(*format, structure, absolue(i), j);
	}
	else if (j > 0 && j < i && i > 0)
	{
		fct2(*format, structure, i, j);
		fct1(*format, structure, j);
	}
	else if (j <= 0 && i < 0)
		norm8(format, structure, i, j);
}

int		cond1(int i, int j)
{
	if ((j > 0 && j >= absolue(i)) || (j > 0 && j < absolue(i) && i < 0)
		|| (j > 0 && j < i && i > 0) || (j <= 0 && i < 0))
		return (1);
	else
		return (0);
}
