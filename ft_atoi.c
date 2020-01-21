/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:55:28 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 01:06:17 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		white_digit(int c, int d)
{
	if (d == 0)
	{
		if (c == '\n' || c == '\t' || c == '\v' || c == ' '
				|| c == '\f' || c == '\r')
			return (1);
		return (0);
	}
	return (-1);
}

static int		checkoverint(long int number, int sym)
{
	if (sym == 2)
		number *= -1;
	if ((number) / 10 > 2147483647)
		return (-1);
	else if ((number) / 10 < -2147483648)
		return (0);
	return (-33);
}

int				ft_atoi(const char *str)
{
	long int	number;
	int			c;

	number = 0;
	c = 0;
	if (*str == '\0')
		return (0);
	while (white_digit(*str, 0) == 1)
		str++;
	if (*str == '-')
		c = 2;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		number += *str - '0';
		number *= 10;
		if (checkoverint(number, c) != -33)
			return (checkoverint(number, c));
		str++;
	}
	if (c == 2)
		number *= -1;
	return (number / 10);
}

int				is_flag(char c)
{
	return (c == '*' || c == '.' || c == '-' || (c >= '0' && c <= '9'));
}
