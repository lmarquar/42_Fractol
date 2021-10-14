/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <leon.marquardt@gmx.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:56:11 by lmarquar          #+#    #+#             */
/*   Updated: 2021/10/05 17:56:12 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static
double	getfloat(char *nptr)
{
	double	res;
	double	mult;

	res = 0.0;
	mult = 0.1;
	if (*nptr == '.')
		nptr++;
	while (*nptr)
	{
		res = res + (*nptr - '0') * mult;
		mult = mult * 0.1;
		nptr++;
	}
	return (res);
}

static
double	transform(char *nptr, int si, int x10)
{
	double	res;
	int		i;
	double	ifloat;

	res = 0;
	i = si;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	ifloat = getfloat(&nptr[i]);
	if (x10 < 0)
		ifloat = ifloat * -1;
	i--;
	while (i >= si && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') * x10 + res;
		x10 = x10 * 10;
		i--;
	}
	res = res + ifloat;
	return (res);
}

double	ft_atod(char *nptr)
{
	int		i;
	double	res;
	int		x10;

	i = 0;
	x10 = 1;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-')
	{
		x10 = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] == '0')
		i++;
	res = transform(nptr, i, x10);
	return (res);
}
