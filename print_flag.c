/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:34:57 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 00:59:46 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	which_format(const char *string, t_list_type *structure)
{
	int i;
	int	sup;

	sup = g_counter;
	i = support1(string);
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
	g_counter += sup;
}

void	construction_string(const char **format,
		t_flag *flaag, t_list_type *structure)
{
	char	*string;
	int		k;
	t_list3	*liste3;

	liste3 = malloc(sizeof(t_list3));
	string = ft_calloc(1, 2);
	liste3->i = 0;
	liste3->j = 0;
	k = 0;
	while (is_format((*format)[k]) == 0)
		k++;
	string[(liste3->i)++] = '%';
	if ((*format)[indice(*format, '*') - 1] == '-' && flaag->integer1 == 0)
		laast(format);
	liste3->format = *format;
	if (condition4(*format, structure, k, liste3->j) == 1)
		support(&string, structure, flaag, liste3);
	else if ((*format)[liste3->j] == '0' && (*format)[liste3->j + 1] == '*'
			&& flaag->integer1 < 0 && how_many(*format, '*') == 1)
		support5(&string, structure, flaag, liste3);
	else
		support9(&string, structure, flaag, liste3);
	free(string);
	free(liste3);
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

char	*ft_strjoin(char const *s1, char const *s2)
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
