/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:48:44 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:29:22 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsign_length(unsigned long long n)
{
	int					i;
	unsigned long long	nb;

	if (n == 0)
		return (1);
	i = 0;
	nb = n;
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		negative(const char *format, t_list_type *structure)
{
	int	i;
	int	count;

	i = 0;
	while (format[i] != '\0' && is_format(format[i]) == 0)
		i++;
	if ((format[i] == 'd' || format[i] == 'i') && structure->integer < 0)
		count = 1;
	else
		count = 0;
	return (count);
}

int		types_absolue(const char *format, t_list_type *structure)
{
	int	i;

	i = 0;
	while (is_format(format[i]) == 0 && format[i] != '\0')
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		i = number_length(absolue(structure->integer));
	else if (format[i] == 'u')
		i = unsign_length(structure->unsign);
	else if (format[i] == 's')
		i = ft_strlen(structure->string);
	else if (format[i] == 'c')
		i++;
	else if (format[i] == 'x')
		i = ft_strlen(dec_to_hexax(structure->unsign));
	else if (format[i] == 'X')
		i = ft_strlen(dec_to_hexaxx(structure->unsign));
	else if (format[i] == 'p')
		i = ft_strlen(dec_to_hexax(structure->pointer)) + 2;
	return (i);
}

void	put_string(const char *format, int j, t_list_type *structure)
{
	int		k;
	char	*string;

	k = 0;
	while (format[k] != '\0' && is_format(format[k]) == 0)
		k++;
	if (format[k] == 'x')
	{
		k = 0;
		string = dec_to_hexax(structure->unsign);
		while (j-- > 0)
			ft_putchar(string[k++]);
	}
	else if (format[k] == 'X')
		aux7(structure, j);
	else if (format[k] == 's')
	{
		k = 0;
		while (j-- > 0)
			ft_putchar(structure->string[k++]);
	}
}

void	print_negative(const char **format)
{
	char	*s;
	int		i;
	int		k;

	k = 1;
	i = 0;
	if (**format == '-')
	{
		k = -1;
		while (**format == '-')
			(*format)++;
	}
	while ((*format)[i] >= '0' && (*format)[i] <= '9')
		i++;
	s = malloc(i + 1);
	i = 0;
	while (is_width(**format) == 1)
		s[i++] = *(*format)++;
	s[i] = '\0';
	print_spaces(s);
	while (is_format(**format) == 0)
		(*format)++;
	(*format)++;
	free(s);
}
