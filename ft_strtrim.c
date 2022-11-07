/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:59:38 by dtelnov           #+#    #+#             */
/*   Updated: 2022/10/11 00:42:00 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	taille(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	size_t	result;

	i = 0;
	result = 0;
	while (s1[i])
	{
		k = 0;
		while (set[k])
		{
			if (s1[i] == set[k])
			{
				result++;
				break ;
			}
			k++;
		}
		i++;
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	i;
	size_t	l;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	tmp = malloc(ft_strlen(s1) - taille(s1, set) + 1);
	if (!tmp)
		return (NULL);
	l = 0;
	i = 0;
	while (s1[i])
	{
		k = 0;
		while (set[k] && set[k] != s1[i])
			k++;
		if (set[k] == '\0')
		{
			tmp[l] = s1[i];
			l++;
		}
		i++;
	}
	tmp[l] = '\0';
	return (tmp);
}
