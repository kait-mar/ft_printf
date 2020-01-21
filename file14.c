/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:19:29 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:26:33 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	support6(char **string, t_list_type *structure,
		t_flag *flaag, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	(*string)[(liste->i)++] = format[(liste->j)++];
	(*string)[liste->i] = '\0';
	*string = ft_strjoin((const char *)(*string), ft_itoa(flaag->integer2));
	liste->i = ft_strlen(*string);
	(liste->j)++;
	(*string)[(liste->i)++] = format[liste->j];
	(*string)[liste->i] = '\0';
	which_format((const char *)(*string), structure);
}

void	support7(char **string, t_list_type *structure, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	liste->i = ft_strlen(*string);
	while (is_format(format[liste->j]) == 0 && format[liste->j] != '*')
		(*string)[(liste->i)++] = format[(liste->j)++];
	(*string)[(liste->i)++] = format[liste->j];
	(*string)[liste->i] = '\0';
	which_format((const char *)(*string), structure);
}

void	support8(char **string, t_list_type *structure, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	(*string)[(liste->i)++] = format[liste->j];
	(*string)[liste->i] = '\0';
	which_format((const char *)(*string), structure);
}

void	support9(char **string, t_list_type *structure,
		t_flag *flaag, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	if (format[liste->j] == '0' &&
		format[liste->j + 1] == '*'
		&& flaag->integer1 < 0)
		(liste->j)++;
	while ((format[liste->j] == '0' ||
		format[liste->j] == '-') || (format[liste->j] != '*'))
		(*string)[(liste->i)++] = format[(liste->j)++];
	(*string)[liste->i] = '\0';
	*string = ft_strjoin((const char *)(*string), ft_itoa(flaag->integer1));
	liste->i = ft_strlen(*string);
	(liste->j)++;
	if (find(format, '.') == 1 && how_many(format, '*') == 2)
		support6(string, structure, flaag, liste);
	else if (find(format, '.') == 1 && how_many(format, '*') == 1)
		support7(string, structure, liste);
	else
		support8(string, structure, liste);
}

void	support(char **string, t_list_type *structure,
		t_flag *flaag, t_list3 *liste3)
{
	const char	*format;

	format = liste3->format;
	if (flaag->integer1 < 0 && format[(liste3->j)] == '0')
		(liste3->j)++;
	while ((format[liste3->j] == '0' ||
		format[liste3->j] == '-') ||
		(format[liste3->j] != '*'))
		(*string)[(liste3->i)++] = format[(liste3->j)++];
	(*string)[(liste3->i)] = '\0';
	*string = ft_strjoin((const char *)string, ft_itoa(flaag->integer1));
	liste3->i = ft_strlen(*string);
	(liste3->j)++;
	if (find(format, '.') == 1 && how_many(format, '*') == 2)
		support2(string, structure, flaag, liste3);
	else if (find(format, '.') == 1 && how_many(format, '*') == 1)
		support3(string, structure, liste3);
	else
		support4(string, structure, liste3);
}
