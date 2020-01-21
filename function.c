/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:50:12 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:23:15 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fct1_negatif(int j)
{
	while (j-- > 0)
		ft_putchar('0');
}

void	fct4_negatif(int i)
{
	if (i >= 0)
	{
		i -= 1;
		while (i-- > 0)
			ft_putchar(' ');
		ft_putchar('0');
	}
	else
	{
		i = absolue(i) - 1;
		ft_putchar('0');
		while (i-- > 0)
			ft_putchar(' ');
	}
}

void	fct2_negatif(int i, int j)
{
	i = absolue(i);
	if (j > 0)
		i = i - j;
	while (i-- > 0)
		ft_putchar(' ');
}

void	fct3_negatif(int i)
{
	while (i-- > 0)
		ft_putchar('0');
}

void	function(const char **format, t_list_type *structure)
{
	t_list2	*structe;

	structe = malloc(sizeof(t_list2));
	structe->test_0 = 0;
	while ((*format)[structe->test_0] != '\0'
	&& is_format((*format)[structe->test_0]) == 0)
		(structe->test_0)++;
	if ((*format)[structe->test_0] == '%')
		print_c(format, structure);
	else
		last_function(format, structure, structe);
	free(structe);
}
