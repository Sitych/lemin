/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:14:17 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/07/28 23:48:19 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int   ft_bellman_ford(t_graph *g, t_room *start)
{
  int		i;
  int		j;
  int		w;
  t_room	*u;
  t_room	*v;

  i = 0;
  j = 0;
  bf_reset();
  start->bf = 0;
  //step 1: relax edges |V| - 1 times
  while (i < g->V - 1) {
	while (j < g->E) {
		u = g->edges[j].u;
		v = g->edges[j].v;
		w = *(g->edges[j].w);
    //   ft_printf("%s -> %s weight %d \n", u->name, v->name, w);
		if (w == -2)
		{
			j++;
			continue ;
		}
	  	if (u->bf != INFINITY && v->bf > u->bf + w)
        	v->bf = u->bf + w;
		j++;
	  }
	  i++;
  }
//   //step 2: detect negative cycle
//   //if value changes then we have a negative cycle in the graph
//   //and we cannot find the shortest distances
//   i = 0;
//   while (i < g->E)
//   {
// 	u = g->edges[j].u;
//     v = g->edges[j].v;
//     w = *(g->edges[j].w);
//     if (u->bf != INFINITY && v->bf > u->bf + w) {
//       ft_printf("Negative weight cycle detected!\n");
//       return (0);
//     }
//   }
  return (1);
}

void		ft_insert_all_edges(char *u, char *v, int i, t_all_edges **edges)
{
	t_edge	*link;

	link = ft_find_data(u)->links;
	while (ft_strcmp(link->name, v))
		link = link->next;
	
	(*edges)[i].u = ft_find_data(u);
	// ft_printf("TYT2\n");
	(*edges)[i].v = ft_find_data(v);
	(*edges)[i].w = &(link->weight);

	link = ft_find_data(v)->links;
	while (ft_strcmp(link->name, u))
		link = link->next;

	(*edges)[i + 1].v = ft_find_data(u);
	(*edges)[i + 1].u = ft_find_data(v);
	(*edges)[i + 1].w = &(link->weight);

	// ft_printf("\n %s \n %s \n %s \n", i, edges[i]->u->name, edges[i + 1]->u->name);
}

//func to reset BF level 
//should be called right after path forming, in order to call bellman_ford func
//and recalculate bf level to form new ways
void	bf_reset(void)
{
	int i;
	i = 0;

	while (i < HTSIZE)
	{
		if (g_htable[i] != NULL)
			g_htable[i]->rooms->bf = INFINITY;
		i++;
	}
}
