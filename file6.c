/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 05:34:46 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 12:56:08 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(char *s)
{
	int	i;

	i = absolue(ft_atoi(s));
	while (i-- > 0)
		ft_putchar(' ');
}

void	aux7(list_type *structure, int j)
{
	char	*string;
	int		k;

	k = 0;
	string = dec_to_hexaX(structure->unsign);
	while (j-- > 0)
		ft_putchar(string[k++]);
}

void	aux8(char **str, list_type *structure)
{
	(*str)[0] = '0';
	(*str)[1] = 'x';
	(*str)[2] = '\0';
	*str = ft_strjoin(*str, dec_to_hexax(structure->pointer));
}

int		aux9(const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && is_format(format[i]) == 0)
		i++;
	return (i);
}

int		indice(const char *format, char c)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == c)
			return (i);
		i++;
	}
	return (i);
}
