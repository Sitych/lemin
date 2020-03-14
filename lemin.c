/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:07:03 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/11 21:17:14 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	tmp[READ + 1];
	int		i;
	int		len;

	while ((len = read(STDIN_FILENO, tmp, READ)) > 0)
	{
		tmp[len] = 0;
		printf("%s", tmp);
		line = ft_strcat(line, tmp);
	}
	printf("%s", line);
	argc = 1;

}