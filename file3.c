/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:53:41 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:29:52 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(const char **format, t_list_type *structure)
{
	int		count;
	int		test_0;

	count = 1;
	test_0 = 0;
	if (cond10(format) == 1)
		help1(format, structure);
	else
	{
		if (**format == '0' && find_point(*format, '-') == 0)
		{
			test_0 = 1;
			while (**format == '0')
				(*format)++;
		}
		else if (find_point(*format, '-') == 1)
		{
			count = -1;
			while (**format == '-' || **format == '0')
				(*format)++;
		}
		norm5(format, count, test_0, structure);
	}
}

int		find_point(const char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != '.')
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		absolue(long n)
{
	if (n >= 0)
		return (n);
	else
		return (n * (-1));
}

char	*join_char(char *str, char c)
{
	int		i;
	char	*string;

	string = malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i++] != '\0')
		string[i] = str[i];
	string[i++] = c;
	string[i] = '\0';
	return (string);
}

int		how_many(const char *format, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (is_format(format[i]) == 0 && format[i] != '\0')
	{
		if (format[i] == c)
			k++;
		i++;
	}
	return (k);
}
