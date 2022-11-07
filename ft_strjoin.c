/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:51:26 by dtelnov           #+#    #+#             */
/*   Updated: 2022/10/11 00:41:15 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (len + len2) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		tmp[len + i] = s2[i];
		i++;
	}
	tmp[len + i] = '\0';
	return (tmp);
}
