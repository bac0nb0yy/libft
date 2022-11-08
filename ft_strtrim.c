/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:59:38 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/08 12:47:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	check(char const *set, char a)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	size_t	debut_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && check(set, s1[i]) == 1)
		i++;
	return (i);
}

static	size_t	fin_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && check(set, s1[ft_strlen(s1) - i - 1]) == 1)
		i++;
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	debut;
	size_t	fin;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	debut = debut_index(s1, set);
	fin = fin_index(s1, set);
	if (debut >= fin)
		return (ft_strdup(""));
	tmp = malloc(sizeof(char) * (fin - debut + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (debut < fin)
	{
		tmp[i] = s1[debut];
		i++;
		debut++;
	}
	tmp[i] = '\0';
	return (tmp);
}
