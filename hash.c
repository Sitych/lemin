/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/07/16 21:30:46 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_hash(char *data)
{
	int	key;
	int	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	return (key % HTSIZE);
}

void		ft_thprint(void)
{
	t_htable	*ptr;
	int i;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		if (ptr != NULL)
		{
			while (ptr != NULL)
			{
				ft_print(ptr->rooms);
				ptr = ptr->next;
			}
		}
		i++;
	}
}

t_room		*ft_find_data(char *data)
{
	t_htable	*p;
	int			key;

	key = ft_hash(data);
	p = g_htable[key];
	while (p != NULL)
	{
		if (!ft_strcmp(p->rooms->name, data))
			return (p->rooms);
		p = p->next;
	}
	return (NULL);
}

void		ft_del_htable(void)
{
	int 		i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		while (ptr != NULL)
		{
			ft_del_room(&(ptr->rooms));
			ptr = ptr->next;
		}
		i++;
	}
}

t_room	*ft_find_start(void)
{
	int			i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		if (ptr != NULL)
			while (ptr != NULL)
			{
				if (ptr->rooms->bfs_level == 0)
					return (ptr->rooms);
				ptr = ptr->next;
			}
		i++;
	}
	return (NULL);
}

t_room	*ft_find_end(void)
{
	int			i;
	t_htable	*ptr;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		if (ptr != NULL)
			if (ptr->rooms->bfs_level == INT_MAX)
				return (ptr->rooms);
		i++;
	}
	return (NULL);
}
