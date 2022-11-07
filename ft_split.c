/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:56:44 by dtelnov           #+#    #+#             */
/*   Updated: 2022/10/11 00:39:58 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	compter_malloc_mot(char const *s, char c)
{
	size_t	result;
	size_t	i;
	size_t	mot;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		mot = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			mot++;
			i++;
		}
		if (mot)
			result = result + 1;
		if (mot == ft_strlen(s) || i >= ft_strlen(s) - 1)
			break ;
		i++;
	}
	return (result);
}

static	size_t	get_taille_mot(size_t index, char const *s, char c)
{
	size_t	result;

	result = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		result++;
		index++;
	}
	return (result);
}

static	void	remplir_mot(size_t start, size_t end, char const *s, char *tmp)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
}

static	int	*freetout(char **tmp, size_t index)
{
	int	i;

	i = index;
	while (i >= 0)
	{
		free(tmp[i]);
		i--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	p;
	size_t	index;

	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char *) * (compter_malloc_mot(s, c) + 1));
	if (!tmp)
		return (NULL);
	p = 0;
	index = 0;
	while (p < ft_strlen(s))
	{
		if (get_taille_mot(p, s, c) >= 1)
		{
			tmp[index] = malloc(sizeof(char) * (get_taille_mot(p, s, c) + 1));
			if (!tmp[index])
				freetout(tmp, index);
			remplir_mot(p, p + get_taille_mot(p, s, c), s, tmp[index]);
			index++;
		}
		p = p + get_taille_mot(p, s, c) + 1;
	}
	tmp[compter_malloc_mot(s, c)] = NULL;
	return (tmp);
}
