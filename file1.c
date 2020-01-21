/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:26:21 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:26:52 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join(const char *s, char c)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen((char *)s) + 2);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	fct1(const char *format, t_list_type *structure, int j)
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

void	fct2(const char *format, t_list_type *structure, int i, int j)
{
	j = j - types_absolue(format, structure);
	if (j > 0)
		i = i - j - types(format, structure);
	else
		i = i - types(format, structure);
	while (i-- > 0)
		ft_putchar(' ');
}

void	fct3(const char *format, t_list_type *structure, int i)
{
	i = i - types(format, structure);
	while (i-- > 0)
		ft_putchar('0');
}
