/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:35:51 by hakalkan          #+#    #+#             */
/*   Updated: 2025/07/13 17:16:29 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == cc)
		return ((char *)s + i);
	return (0);
}
