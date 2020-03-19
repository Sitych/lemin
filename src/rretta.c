/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rretta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:17:14 by rretta            #+#    #+#             */
/*   Updated: 2020/03/19 17:44:56 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_val_links2(char **split, int j, int i)
{
	char	**links;

	while (j <= i)
	{

		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((links = ft_strsplit(split[i], '-')) == NULL)
				ft_exit("ERROR: SPLIT ERROR");
		if ((ft_find_data(links[0]) == NULL) || (ft_find_data(links[1]) == NULL))
			ft_exit("ERROR: NO SUCH ROOM NAME IN THE LINK INPUT");
		if (ft_strcmp(links[0], links[1]) == 0)
			ft_exit("ERROR: LINK IS LINKED TO ITSELF");
		if (j != i)
		{	
			if (ft_strcmp(split[j], split[i]) == 0)
				ft_exit("ERROR: LINK IS REPEATED");
		}
		j++;
		ft_free((void**)links, 2);
	}
	return (0);
}