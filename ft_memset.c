/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:51:19 by dtelnov           #+#    #+#             */
/*   Updated: 2022/09/04 19:39:40 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
    char str[50];
    char str2[50];

    // strcpy(str,"This is string.h library function");
    // puts(str);

    strcpy(str2,"This is string.h library function");
    puts(str2);

    // memset(str,'$',7);
    // puts(str);

    memset(str2,'$',7);
    puts(str2);

   return(0);
}
*/
