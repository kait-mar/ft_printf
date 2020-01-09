/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:27:18 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 11:23:38 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	which_format(const char *string, list_type *structure)
{
	int i;

	i = 0;
	if (string[i] == '%')
		i++;
	while (is_format(string[i]) == 0)
		i++;
	if (string[i] == 'd' || string[i] == 'i')
		ft_printf(string, structure->integer);
	else if (string[i] == 's')
		ft_printf(string, structure->string);
	else if (string[i] == 'u')
		ft_printf(string, structure->unsign);
	else if (string[i] == 'x' || string[i] == 'X')
		ft_printf(string, structure->unsign);
	else if (string[i] == 'c')
		ft_printf(string, structure->car);
	else if (string[i] == 'p')
		ft_printf(string, structure->pointer);
	else if (string[i] == '%')
		ft_printf(string);
}

void	construction_string(const char *format, flag *s_flag, list_type *structure)
{
	char	*string;
	int		i;
	int		j;
	int		k;

	string = ft_calloc(1, 2);
	i = 0;
	j = 0;
	k = 0;
	while (is_format(format[k]) == 0)
		k++;
	string[i++] = '%';
	if (condition4(format, structure, k, j) == 1)
	{
		if (s_flag->integer1 < 0 && format[j] == '0')
			j++;
		while ((format[j] == '0' || format[j] == '-') || (format[j] != '*'))
			string[i++] = format[j++];
		string[i] = '\0';
		string = ft_strjoin((const char *)string, ft_itoa(s_flag->integer1));
		i = ft_strlen(string);
		j++;
		if (find(format, '.') == 1 && how_many(format, '*') == 2)
		{
			string[i++] = format[j++];
			string[i] = '\0';
			string = ft_strjoin((const char *)string, ft_itoa(s_flag->integer2));
			i = ft_strlen(string);
			j++;
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
		else if (find(format, '.') == 1 && how_many(format, '*') == 1)
		{
			i = ft_strlen(string);
			while (is_format(format[j]) == 0 && format[j] != '*')
				string[i++] = format[j++];
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
		else
		{
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
	}
	else if (format[j] == '0' && format[j + 1] == '*' && s_flag->integer1 < 0 && how_many(format, '*') == 1)
	{
		string[i] = '\0';
		string = ft_strjoin((const char *)string, ft_itoa(s_flag->integer1));
		while (is_format(format[j]) == 0 && format[j] != '\0')
				j++;
		string[ft_strlen(string)] = format[j];
		string[ft_strlen(string) + 1] = '\0';
		which_format((const char *)string, structure);
	}
	else
	{
		if (format[j] == '0' && format[j + 1] == '*' && s_flag->integer1 < 0)
			j++;
		while ((format[j] == '0' || format[j] == '-') || (format[j] != '*'))
			string[i++] = format[j++];
		string[i] = '\0';
		string = ft_strjoin((const char *)string, ft_itoa(s_flag->integer1));
		i = ft_strlen(string);
		j++;
		if (find(format, '.') == 1 && how_many(format, '*') == 2)
		{
			string[i++] = format[j++];
			string[i] = '\0';
			string = ft_strjoin((const char *)string, ft_itoa(s_flag->integer2));
			i = ft_strlen(string);
			j++;
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
		else if (find(format, '.') == 1 && how_many(format, '*') == 1)
		{
			i = ft_strlen(string);
			while (is_format(format[j]) == 0 && format[j] != '*')
				string[i++] = format[j++];
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
		else
		{
			string[i++] = format[j];
			string[i] = '\0';
			which_format((const char *)string, structure);
		}
	}
}

int		find(const char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && is_format(string[i]) == 0)
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;
	int		k;

	if (s1 == 0 || s2 == 0)
		return (0);
	string = malloc(strlen(s1) + strlen(s2) + 1);
	if (string == 0)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
		string[k++] = s1[i++];
	while (s2[j] != '\0')
		string[k++] = s2[j++];
	string[k] = '\0';
	return (string);
	return (0);
}
