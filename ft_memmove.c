/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:50:50 by dtelnov           #+#    #+#             */
/*   Updated: 2022/09/13 22:13:53 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((unsigned char *)dest < (unsigned char *)src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else if ((unsigned char *)dest > (unsigned char *)src)
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char *)(dest + i - 1) = *(unsigned char *)(src + i - 1);
			i--;
		}
	}
	return (dest);
}
