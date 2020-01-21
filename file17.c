/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file17.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:39:21 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/11 14:34:39 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help18(t_list_type *structure, int i, int j)
{
	int	k;

	k = 0;
	i = i - absolue(j);
	while (i-- > 0)
		ft_putchar(' ');
	j = absolue(j);
	while (j-- > 0)
		ft_putchar(structure->string[k++]);
}

void	help19(t_list_type *structure, int i, int j)
{
	int	k;

	k = 0;
	i = absolue(i) - j;
	j = absolue(j);
	while (j-- > 0)
		ft_putchar(structure->string[k++]);
	while (i-- > 0)
		ft_putchar(' ');
}
