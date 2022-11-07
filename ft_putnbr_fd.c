/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:27:46 by dtelnov           #+#    #+#             */
/*   Updated: 2022/09/24 00:56:06 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	write_number(int n, int fd)
{
	char	chiffre;

	if (n == 0)
		return ;
	write_number(n / 10, fd);
	chiffre = n % 10 + '0';
	write(fd, &chiffre, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	write_number(n, fd);
}
