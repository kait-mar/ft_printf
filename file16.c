/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:33:43 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:32:07 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		condii(int i, int j)
{
	return ((j > 0 && j < absolue(i) && i < 0)
	|| (j > 0 && j < i && i > 0));
}

int		cond13(const char **format)
{
	while (**format == '0')
		(*format)++;
	return (1);
}

int		cond14(const char **format)
{
	return (**format == '0' &&
			!(is_width(*(*format + 1)) == 1
			&& (*format)[indice(*format, '.') + 1] != '-'));
}

int		cond15(const char **format, t_list_type *structure, int k)
{
	return ((((*format)[k] == 'd'
			|| (*format)[k] == 'i')
			&& structure->integer == 0)
			|| (((*format)[k] == 'x' ||
			(*format)[k] == 'X'
			|| (*format)[k] == 'u')
			&& structure->unsign == 0));
}

void	last_function(const char **format,
		t_list_type *structure, t_list2 *structe)
{
	int	k;

	if (cond14(format) == 1)
		structe->test_0 = cond13(format);
	structe->i = first_str(format);
	if (**format == '.')
		(*format)++;
	structe->j = first_str(format);
	k = 0;
	while (is_format((*format)[k]) == 0 && (*format)[k] != '\0')
		k++;
	if (cond15(format, structure, k) == 1)
		help_d(structe->i, structe->j, structe->test_0);
	else if ((*format)[k] == 's')
		help_string(structure, structe->i, structe->j);
	else if ((*format)[k] == 'p' && structure->pointer == 0)
		help_pointer(format, structure, structe->i, structe->j);
	else
		help_others(format, structure, structe);
	(*format)++;
}
