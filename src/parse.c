/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:22 by erodd             #+#    #+#             */
/*   Updated: 2020/03/11 23:01:49 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_file_parse(char **split)
{
	char	tmp[4096 + 1];
	char	*str;
	char	*str2;
	int len;

	str = "";
	str2 = "";
	ft_memset(tmp, '\0', 4096);
	while ((len = read(STDIN_FILENO, tmp, 4096)) > 0)
	{
		tmp[len] = '\0';
		str2 = ft_strjoin(str, tmp);
		if (*str != '\0')
			free(str);
		str = str2;
	}
	if (ft_strstr(str2, "\n\n") != 0)
	{
		perror("ERROR: EMPTY LINE");
		exit (EXIT_FAILURE);
	}
	split = ft_strsplit(str2, '\n');
	ft_strdel(&str2);
	return (split);
}

int	ft_word_counter(char const *s, char c)
{
	int	q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}
