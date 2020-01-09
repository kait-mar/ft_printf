/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:26:21 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 10:13:01 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join(const char *s, char c)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen((char *)s) + 2);
	i= 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	fct1(const char *format, list_type *structure, int j)
{
	int	k;

	k = 0;
	j = j - types_absolue(format, structure);
	while (is_format(format[k]) == 0 && format[k] != '\0')
		k++;
	if (structure->integer < 0 && (format[k] == 'd' || format[k] == 'i'))
		ft_putchar('-');
	while (j-- > 0)
		ft_putchar('0');
	print_format(format, structure);
}

void	fct2(const char *format, list_type *structure, int i, int j)
{
	j = j - types_absolue(format, structure);
	if (j > 0)
		i = i - j - types(format, structure);
	else
		i = i - types(format, structure);
	while (i-- > 0)
		ft_putchar(' ');
}

void	fct3(const char *format, list_type *structure, int i)
{
		i = i - types(format, structure);
	while (i-- > 0)
		ft_putchar('0');
}

void	function(const char **format, list_type *structure)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;
	int		k;
	int		test_0;

	k = 1;
	test_0 = 0;
	while ((*format)[test_0]!= '\0' && is_format((*format)[test_0]) == 0)
		test_0++;
	if ((*format)[test_0] == '%')
		print_c(format, structure);
	else
	{
		 if(**format == '0' && !(is_width(*(*format + 1)) == 1 && (*format)[indice(*format, '.') + 1] != '-'))
		{
			test_0 = 1;
			while (**format == '0')
				(*format)++;
		}
	i = 0;
	j = 0;
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
	if (**format == '.')
		(*format)++;
	if (**format == '-')
	{
		k = -1;
		(*format)++;
	}
	else
		k = 1;
	while (is_width((*format)[j]) == 1)
		j++;
	s2 = malloc(j + 1);
	j = 0;
	while (is_width(**format) == 1)
	{
		s2[j++] = **format;
		(*format)++;
	}
	s2[j] = '\0';
	j = ft_atoi(s2) * k;
	k = 0;
	while (is_format((*format)[k]) == 0 && (*format)[k] != '\0')
		k++;
	if (((*format)[k] == 'd' || (*format)[k] == 'i') &&  i == 0 && j == 0 && structure->integer == 0)
	{
		while (is_format(**format) == 0)
			(*format)++;
	}
	else if ((*format)[k] == 's')
	{
		k = 0;
		if (j < ft_strlen(structure->string) && i >= 0 && j >= 0)
		{
			i = i - absolue(j);
			while (i-- > 0)
				ft_putchar(' ');
			j = absolue(j);
			while (j-- > 0)
				ft_putchar(structure->string[k++]);
		}
		else if (j < ft_strlen(structure->string) && i <= 0 && j >= 0)
		{
			i = absolue(i) - j;
			j = absolue(j);
			while (j-- > 0)
				ft_putchar(structure->string[k++]);
			while (i-- > 0)
				ft_putchar(' ');
		}
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
	else if (condition9(format, structure, k) == 1)
		norm6(format, i, k);
	else
	{
		if (cond1(i, j) == 1)
		fct5(format, structure, i, j);
		else if (j <= 0 && i >= 0)
		{
			if(test_0 == 1)
				norm9(format, structure, i);
			else
				fct4(format, structure, i, j);
			print_format(*format, structure);
		}
	}
	(*format)++;
	}
}