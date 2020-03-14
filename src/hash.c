/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/14 22:06:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t			ft_hash(char *data)
{
	size_t	key;
	size_t	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	return (key);
}



t_hash_table	*ft_insert_data(t_r_list *room)
{
	t_hash_table	*p;
	t_hash_table	*p0;
	size_t			bucket;

	bucket = ft_hash(room->name);
	if ((p = (t_hash_table*)malloc(sizeof(t_hash_table))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_hash_table[bucket];
	g_hash_table[bucket] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

t_hash_table	*ft_find_data(char *data)
{
	t_hash_table	*p;

	p = g_hash_table[ft_hash(data)];
	return (p);
}
