/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 05:39:08 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:31:40 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		first_str(const char **format)
{
	char	*s1;
	int		i;
	int		k;

	i = 0;
	k = 1;
	if (**format == '-')
		k = -1;
	while (**format == '-')
		(*format)++;
	while (is_width((*format)[i]) == 1)
		i++;
	s1 = malloc(i + 1);
	i = 0;
	while (is_width(**format) == 1)
	{
		s1[i++] = **format;
		(*format)++;
	}
	s1[i] = '\0';
	i = ft_atoi(s1) * k;
	free(s1);
	return (i);
}

void	help_string(t_list_type *structure, int i, int j)
{
	int	k;

	k = 0;
	if (j < ft_strlen(structure->string) && i >= 0 && j >= 0)
		help18(structure, i, j);
	else if (j < ft_strlen(structure->string) && i <= 0 && j >= 0)
		help19(structure, i, j);
	else if (j < 0 || j >= ft_strlen(structure->string))
	{
		if (i > 0)
		{
			i = i - ft_strlen(structure->string);
			while (i-- > 0)
				ft_putchar(' ');
			ft_putstr(structure->string);
		}
		else
		{
			i = absolue(i) - ft_strlen(structure->string);
			ft_putstr(structure->string);
			while (i-- > 0)
				ft_putchar(' ');
		}
	}
}

void	help_pointer(const char **format, t_list_type *structure, int i, int j)
{
	if (i < 0)
	{
		i = absolue(i) - 2;
		ft_putchar('0');
		ft_putchar('x');
		while (i-- > 0)
			ft_putchar(' ');
	}
	else if (i > 0 || (i == 0 && j == 0))
		help404(i, j);
	else if (i == 0 && j > 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		while (i-- > 0)
			ft_putchar('0');
	}
	else
		print_format(*format, structure);
}

void	help_d(int i, int j, int test_0)
{
	if (j == 0)
		fct2_negatif(i, j);
	if (j > 0 && j >= absolue(i))
		fct1_negatif(j);
	else if (j > 0 && j < absolue(i) && i < 0)
	{
		fct1_negatif(j);
		fct2_negatif(absolue(i), j);
	}
	else if (j > 0 && j < i && i > 0)
	{
		fct2_negatif(i, j);
		fct1_negatif(j);
	}
	else if (j < 0 && i == 0)
		ft_putchar('0');
	else if (j < 0)
	{
		if (test_0 == 1)
			fct3_negatif(i);
		else
			fct4_negatif(i);
	}
}

void	help_others(const char **format,
		t_list_type *structure, t_list2 *structe)
{
	if (structe->j > 0 && structe->j >= absolue(structe->i))
		fct1(*format, structure, structe->j);
	else if (condii(structe->i, structe->j) == 1)
		help17(format, structure, structe->i, structe->j);
	else if (structe->j <= 0 && structe->i < 0)
		help15(format, structure, structe->i, structe->j);
	else if (structe->j <= 0 && structe->i >= 0)
	{
		if (structe->test_0 == 1)
			help14(format, structure, structe->i);
		else
			help15(format, structure, structe->i, structe->j);
	}
}
