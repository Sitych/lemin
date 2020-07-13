/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:06:02 by rretta            #+#    #+#             */
/*   Updated: 2020/07/10 20:48:51 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way_node	*ft_create_node(char *room_name)
{
	t_way_node	*tmp;
	tmp = NULL;
	
	if ((tmp = (t_way_node*)malloc(sizeof(t_way_node))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((tmp->name = ft_strdup(room_name)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->next = NULL;
	return (tmp);
}

// t_way_node	*ft_path_finding(t_room *room)
// {

// }

t_room		*ft_find_min_bfs_room(t_room *room)
{
	t_edge	*links;
	int min_bfs;
	t_room	*tmp;

	tmp = NULL;
	min_bfs = INT_MAX;
	links = room->links;
	while (links != NULL)
	{
		if (ft_find_data(links->name)->bfs_level < min_bfs && ft_find_data(links->name)->bfs_level != -1)
		{
			min_bfs = ft_find_data(links->name)->bfs_level;
			tmp = ft_find_data(links->name);
			printf("Node: %s bfs: %d\n", ft_find_data(links->name)->name, min_bfs);
		}
		links = links->next;
	}
	printf("%d", min_bfs);
	return (tmp);
}