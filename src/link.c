/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 23:58:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/08 20:52:08 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_val_links2(char **split, int j, int i, char **links)
{
	while (j <= i)
	{
		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((ft_find_data(links[0]) == NULL) || (ft_find_data(links[1]) == NULL))
			ft_exit("ERROR: NO SUCH ROOM NAME IN THE LINK INPUT");
		if (ft_strcmp(links[0], links[1]) == 0)
			ft_exit("ERROR: LINK IS LINKED TO ITSELF");
		if (j != i)
			if (ft_strcmp(split[j], split[i]) == 0)
				ft_exit("ERROR: LINK IS REPEATED");
		j++;
	}
	return (0);
}

char	**ft_swap_links(char **str, char **link)
{
	char	delimeter;
	char	*buf;

	delimeter = '-';
	if (ft_strcmp(link[0], link[1]) <= 0)
		return (link);
	else
	{
		buf = link[0];
		link[0] = link[1];
		link[1] = buf;
		ft_strcpy(*str, link[1]);
		ft_strncat(*str, &delimeter, 1);
		ft_strcat(*str, link[0]);
	}
	return (link);
}

void		ft_set_links(char ***links, int i, int all, t_graph **g)
{
	char		**link;
	int			j;
	int			c;

	j = 0;
	c = 0;
	while (j < all - i)
	{
		
		if (links[j][0][0] == '#')
		{
			j++;
			continue ;
		}
		link = links[j];
		// ft_printf("TYT");
		ft_insert_link(link[0], link[1]);
		ft_insert_link(link[1], link[0]);
		ft_insert_all_edges(link[0], link[1], c, &((*g)->edges));
		ft_free((void**)links[j], 2);
		j++;
		c = c + 2;
		// ft_printf("%d \n", *((*g)->edges[c]->w));
	}
	free(links);
}

t_room		*ft_insert_link(char *room, char *link)
{
	t_room	*p;
	t_edge	*links;

	p = ft_find_data(room);
	if (p->links == NULL)
	{
		p->links = ft_creat_edge(link);
		return (p);
	}
	links = p->links;
	while (links->next != NULL)
		links = links->next;
	links->next = ft_creat_edge(link);
	(links->next)->prev = links;
	return (p);
}

int			ft_manage_way(t_graph *g, t_room *room)
{
	t_edge	*start;
	int		count;

	if (!ft_strcmp(g->end->name, room->name))
		return (0);
	start = room->links;
	count = 0;
	while (start != NULL)
	{
		if (ft_find_data(start->name)->bfs_level > room->bfs_level)
		{
			if (ft_manage_way(g, ft_find_data(start->name)) == 1)
			{
				--count;
			}
		}
		start = start->next;
		++count;
	}
	if (count == 1 && ft_strcmp(room->name, g->start->name))
		room->bfs_level = -1;
	return (count);
}
