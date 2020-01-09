/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:17:41 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/05 04:59:11 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pow(int a, int b)
{
	if ( b == 0)
		return (1);
	if (b < 0)
		return (0);
	else
		return (a * ft_pow(a, b - 1));
}

char	num_char_X(int n)
{
	if (n >= 0 && n <=  9)
		return (n + '0');
	else
		return (n + 55);
}

char	num_char_x(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else
		return (n + 87);
}

char	*dec_to_hexax(unsigned long long n)
{
	int		i;
	char	*converted;
	char	reverse[unsign_length(n)];
	unsigned long long		nb;

	converted = calloc(1, unsign_length(n) + 1);
	if (n == 0)
	{
		converted[0] = '0';
		converted[1] = '\0';
	}	
	else
	{
	nb = n;
	i = 0;
	while (nb != 0)
	{
		reverse[i++] = num_char_x(nb % 16);
		nb /= 16;
	}
	nb = 0;
	while (--i >= 0)
		converted[nb++] = reverse[i];
	converted[nb] = '\0';
	}
	return (converted);
}

char	*dec_to_hexaX(unsigned long long n)
{
	int		i;
	char	*converted;
	char	reverse[unsign_length(n)];
	unsigned long long		nb;

	converted = calloc(1, unsign_length(n) + 1);
	if (n == 0)
	{
		converted[0] = '0';
		converted[1] = '\0';
	}
	else
	{	
	nb = n;
	i = 0;
	while (nb != 0)
	{
		reverse[i++] = num_char_X(nb % 16);
		nb /= 16;
	}
	nb = 0;
	while (--i >= 0)
		converted[nb++] = reverse[i];
	converted[nb] = '\0';
	}
	return (converted);
}
