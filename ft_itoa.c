/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:30:19 by dtelnov           #+#    #+#             */
/*   Updated: 2022/09/14 03:54:49 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	number_of_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static	char	*min_int(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * 12);
	tmp[0] = '-';
	tmp[1] = '2';
	tmp[2] = '1';
	tmp[3] = '4';
	tmp[4] = '7';
	tmp[5] = '4';
	tmp[6] = '8';
	tmp[7] = '3';
	tmp[8] = '6';
	tmp[9] = '4';
	tmp[10] = '8';
	tmp[11] = '\0';
	return (tmp);
}

static	int	determiner_signe(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		return (-sign);
	return (sign);
}

static	char	*result(int signe, int digits, int n)
{
	char	*result;
	int		taille_malloc;

	if (signe == 1)
		taille_malloc = digits + 1;
	else
		taille_malloc = 1 + digits + 1;
	result = malloc(taille_malloc);
	if (!result)
		return (NULL);
	if (signe == -1)
		result[0] = '-';
	while (digits)
	{
		if (signe == 1)
			result[digits - 1] = (n % 10) + '0';
		else
			result[digits - 1 + 1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	result[taille_malloc - 1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		signe;

	if (n == -2147483648)
		return (min_int());
	else
		digits = number_of_digits(n);
	signe = determiner_signe(n);
	if (signe == -1)
		return (result(signe, digits, -n));
	return (result(signe, digits, n));
}
