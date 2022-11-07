/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:37:25 by dtelnov           #+#    #+#             */
/*   Updated: 2022/10/11 01:28:32 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;
	size_t	fail;

	if (size == 0 || nmemb == 0)
		fail = 1;
	else
		fail = 0;
	if (size > 0 && (nmemb > ((size_t)-1 / size)))
		return (NULL);
	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (!fail)
	{
		i = 0;
		while (i < nmemb * size)
		{
			*((unsigned char *)(ptr + i)) = 0;
			i++;
		}
	}
	return (ptr);
}
