/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:28:42 by kait-mar          #+#    #+#             */
/*   Updated: 2019/10/27 21:55:56 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocation_negative(int n, int len, long num)
{
	char	*integer;

	len = 0;
	num = n;
	while (n != 0 && len++ >= 0)
		n = n / 10;
	integer = (char*)malloc(len + 2);
	if (integer == 0)
		return (0);
	integer[len + 1] = '\0';
	integer[0] = '-';
	num *= (-1);
	while (len > 0)
	{
		integer[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (integer);
}

static char	*allocation_nulle(int n)
{
	char	*integer;

	integer = malloc(2);
	if (integer == 0)
		return (0);
	integer[0] = n + '0';
	integer[1] = '\0';
	return (integer);
}

char		*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*integer;

	len = 0;
	num = n;
	if (n < 0)
		return (allocation_negative(n, len, num));
	else if (n / 10 == 0)
		return (allocation_nulle(n));
	else
	{
		while (n != 0 && len++ >= 0)
			n = n / 10;
		if (!(integer = malloc(len + 2)))
			return (0);
		integer[len--] = '\0';
		while (len >= 0)
		{
			integer[len--] = num % 10 + '0';
			num = num / 10;
		}
		return (integer);
	}
}
