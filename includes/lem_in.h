/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:35 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/05 06:20:40 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h> //DELETE THIS
# include <stdio.h> //DELETE THIS
# include "libft.h"
# include "libftprintf.h"

/*
**	define const value for hash func
*/

# define P			(int)10
# define HTSIZE 	(int)65536
# define INFINITY	INT32_MAX

typedef struct			s_edge
{
	char				*name;
	int					flag;
	int					weight;
	struct s_edge		*prev;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_room
{
	char				*name;
	int					bfs_level;
	int					x;
	int					y;
	int					flag;
	t_edge				*links;
	int					bf;
	int					ant_id;
	int					ants;
}						t_room;

typedef struct			s_way_node
{
	t_room				*name;
	struct s_way_node	*next;
	struct s_way_node	*prev;
}						t_way_node;

typedef struct			s_way
{
	int					way_length;
	struct s_way_node	*start_node;
	struct s_way_node	*end_node;
	struct s_way		*next;
}						t_way;

typedef struct			s_all_edges 
{
  t_room  	*u;  //start vertex in the link
  t_room  	*v;  //end vertex in the link
  int     	*w;  //weight of the edge u->v
  int		*f;
}						t_all_edges;

typedef struct			s_graph
{
  int     ants; //total number of ants
  int 		V;	//total quantity of vertices 
  int 		E;	//total number of edges
  t_all_edges *edges;  //list of edges
}						t_graph;

typedef struct			s_htable
{
	t_room				*rooms;
	struct s_htable		*next;
}						t_htable;

typedef struct			s_queue
{
	char				*name;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_sol
{
	t_way				*way;
	struct s_sol		*next;
}						t_sol;

typedef	unsigned short int t_thindex;

t_htable				*g_htable[HTSIZE];


//init functions
char			**ft_file_parse(char **split);
t_graph			*ft_file_checker(char **split,int all, t_graph *g);
int				ft_val_ant(char *split);
int				ft_val_bond(char **split);
int				ft_val_room(char **split, t_graph **g);
int				ft_val_coords(char **split, int i);
char			***ft_val_links(char **split, int i, int all, t_graph **g);
int				ft_word_counter(char const *s, char c);
void			ft_exit(char *str);
void			ft_prng(unsigned int seed);
int				ft_check_room(char **split, int i);
char			**ft_swap_links(char **str, char **link);
int				ft_val_links2(char **split, int j, int i, char **links);
void			ft_set_links(char ***links, int i, int all, t_graph **g);
t_edge			*ft_creat_edge(char *name);
void			ft_del_edge(t_edge *ptr);

/*
**	FUNC FOR LINKED LIST
*/

t_room		*ft_crtrm(char *str, int flag);
t_room		*ft_add_push_back(t_room *tmp, char **split, int i);
t_room		*ft_roomdel(t_room **ptr);
void			ft_check_name_coord(t_room *ptr);
void			ft_print(t_room *tmp);
void		ft_del_room(t_room **ptr);


/*
**	FUNC FOR HASH TABLE
*/

int				ft_hash(char *data);
t_htable		*ft_insert_room(t_room *room);
t_room			*ft_insert_link(char *room, char *link);
t_room			*ft_find_data(char *data);
void			ft_create_htable(int len);
void			ft_set_htable(char **split, int len);
void			ft_thprint(void);
void			ft_del_htable(void);
t_room			*ft_find_start(void);
t_room			*ft_find_end(void);

/*
** FUNCS FOR QUEUE
*/

t_queue		*ft_creat_elem(char *data);
t_queue		*ft_push(t_queue *head, char *data);
t_queue		*ft_pop(t_queue **head);
int			ft_queue_size(t_queue *head);
int			ft_isempty(t_queue *head);
void		ft_del_elem(t_queue **elem);
void		ft_qprint(t_queue *head);
t_queue		*ft_push_priority(t_queue *head, char *data);

/*
** FUNCS FOR BFS
*/

void		ft_print_bfs(void);

/*
** FUNCS FOR SET WAYS
*/
int			ft_manage_way(t_room *room);
int			ft_V_counter(void);
int			ft_E_counter(int all, int i);
t_way_node	*ft_create_node(t_room *room_name);
t_edge		*ft_find_min_bfs_link(t_edge *links);
t_way		*ft_paste_first_node(t_way *way, t_way_node *node);
t_way		*ft_paste_node(t_way *way, t_way_node *node);
t_way		*ft_find_short_way(t_room *room, t_edge *(*func) (t_edge *link));
t_way		*ft_find_all_short_ways(t_way	*ways);
void		ft_print_way(t_way *way);
int			ft_bellman_ford(t_graph *g, t_room *start);
void		bf_reset(void);


void		ft_insert_all_edges(char *u, char *v, int i, t_all_edges **edges);
t_edge		*ft_find_edge1(t_room *from, t_room *to);
void		ft_null_ways(t_way *ways);
t_way		*ft_find_solution(t_room *room, t_graph *g);
t_edge		*ft_find_minus_one_link(t_edge *links);
void	ft_null(t_graph *g);
t_sol	*ft_solution(t_graph *g);

#endif