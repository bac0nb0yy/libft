/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:50:36 by dtelnov           #+#    #+#             */
/*   Updated: 2022/10/10 21:32:35 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = dest;
	if ((!dest && !src) && n)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "aaaaaaa";
	char b[] = "bcaloxd";
	int	*ptr = a;
	int	*ptr2 = b;
	int	*ptr3;

	printf("%s\n%s\n%d\n", (char *)ptr, (char *)ptr2, ptr3);
	ptr3 = ft_memcpy(ptr, ptr2, 2);
	printf("%d\n", ptr3);
	printf("%s\n", (char *)ptr3);
}
*/
