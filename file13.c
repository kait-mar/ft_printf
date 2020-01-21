/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 08:40:20 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 15:26:33 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		support1(const char *string)
{
	int	i;

	i = 0;
	if (string[i] == '%')
		i++;
	while (is_format(string[i]) == 0)
		i++;
	return (i);
}

void	support2(char **string, t_list_type *structure,
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

void	support3(char **string, t_list_type *structure, t_list3 *liste)
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

void	support4(char **string, t_list_type *structure, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	(*string)[(liste->i)++] = format[liste->j];
	(*string)[liste->i] = '\0';
	which_format((const char *)(*string), structure);
}

void	support5(char **string, t_list_type *structure,
		t_flag *flaag, t_list3 *liste)
{
	const char	*format;

	format = liste->format;
	(*string)[liste->i] = '\0';
	*string = ft_strjoin((const char *)(*string), ft_itoa(flaag->integer1));
	while (is_format(format[liste->j]) == 0 && format[liste->j] != '\0')
		(liste->j)++;
	(*string)[ft_strlen(*string)] = format[liste->j];
	(*string)[ft_strlen(*string) + 1] = '\0';
	which_format((const char *)(*string), structure);
}
