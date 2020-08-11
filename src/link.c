/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 23:58:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/10 16:47:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_val_links2(char **split, int j, int i, char **links)
{
	while (j <= i)
	{
		if (split[j][0] == '#')
		{
			j++;
			continue ;
		}
		if ((ft_find_data(links[0]) == NULL) || \
											(ft_find_data(links[1]) == NULL))
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

static char		**ft_swap_links(char **str, char **link)
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

static t_room	*ft_insert_link(char *room, char *link)
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

void			ft_set_links(char ***links, int i, int all, t_graph **g)
{
	char		**link;
	int			j;
	int			c;

	j = 0;
	c = 0;
	i++;
	all++;
	while (links[j])
	{
		link = links[j];
		ft_insert_link(link[0], link[1]);
		ft_insert_link(link[1], link[0]);
		ft_insert_all_edges(link[0], link[1], c, &((*g)->edges));
		ft_free((void**)links[j], 2);
		j++;
		c = c + 2;
	}
	free(links);
}

char			***ft_val_links(char **links, int i, int all, t_graph **g)
{
	int		j;
	char	***link;

	j = 0;
	if ((link = (char***)ft_memalloc((sizeof(char**)) * \
													(all - (i--) + 1))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		if (ft_word_counter(links[i], '-') == 2)
		{
			if ((link[j] = ft_strsplit(links[i], '-')) == NULL)
				ft_exit("ERROR: SPLIT ERROR");
			link[j] = ft_swap_links(&links[i], link[j]);
			ft_val_links2(links, j, i, link[j]);
			j++;
			(*g)->E += 2;
		}
		else
			ft_exit("ERROR: SHITTY LINK INPUT");
	}
	return (link);
}
