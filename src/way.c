/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:27 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/07/31 22:29:58 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way_node	*ft_create_node(t_room *link_name)
{
	t_way_node	*tmp;
	tmp = NULL;
	
	if ((tmp = (t_way_node*)malloc(sizeof(t_way_node))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->name = link_name;
	tmp->next = NULL;
	return (tmp);
}

t_edge	*ft_find_min_bfs_link(t_edge *links)
{
	int		minbfs;
	t_edge	*minbfslink;

	minbfs = INT32_MAX;
	while (links != NULL)
	{
		if (minbfs > ft_find_data(links->name)->bf && links->weight != -1)
		{
			minbfs = ft_find_data(links->name)->bf;
			minbfslink = links;
		}
		links = links->next;
	}
	if (minbfs == INT32_MAX)
		return (NULL);
	// if (ft_strcmp(minbfslink->name, ft_find_start()->name))
	// 	ft_find_data(minbfslink->name)->flag = -1;
	return (minbfslink);
}

t_way	*ft_paste_node(t_way *way, t_way_node *node)
{
	t_way_node	*buf;

	if (way == NULL)
	{
		if ((way = (t_way*)malloc(sizeof(t_way))) == NULL)
			ft_exit("MALLOC ERROR");
		way->way_length = 1;
		way->start_node = node;
		return (way);
	}
	buf = way->start_node;
	while (buf->next)
		buf = buf->next;
	buf->next = node;
	way->way_length++;
	return (way);
}

t_way	*ft_find_short_way(t_room *room)
{
	t_edge		*link;
	t_way	*shortway;
	
	shortway = NULL;
	shortway = ft_paste_node(shortway, ft_create_node(room));
	if ((link = ft_find_min_bfs_link(room->links)) == NULL)
		return (NULL);
	room = ft_find_data(link->name);
	shortway = ft_paste_node(shortway, ft_create_node(room));
	while (ft_strcmp(room->name, ft_find_start()->name))
	{
		if ((link = ft_find_min_bfs_link(room->links)) == NULL)
			return (NULL);
		shortway = ft_paste_node(shortway, ft_create_node(ft_find_data(link->name)));
		room = ft_find_data(link->name);
	}
	shortway->next = NULL;
	return (shortway);
}

void	ft_print_way(t_way *way)
{
	t_way_node	*node;

	node = way->start_node;
	ft_printf("len = %d\n", way->way_length);
	while (node != NULL)
	{
		ft_printf("%s\n", node->name->name);
		node = node->next;
	}
}

t_way	*ft_find_all_short_ways(t_way	*ways)
{
	t_way		*way;

	ways = ft_find_short_way(ft_find_end());
	way = ways;
	while (way != NULL)
	{
		way->next = ft_find_short_way(ft_find_end());
		way = way->next;
	}
	return (ways);
}

void	ft_null_ways(t_way *ways)
{
	t_way_node	*node;
	t_way		*way;

	way = ways;
	while (way != NULL)
	{
		node = way->start_node;
		while (node != NULL)
		{
			node->name->flag = 1;
			node = node->next;
		}
		way = way->next;
	}
}