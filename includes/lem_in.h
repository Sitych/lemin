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

# define P		(int)10
# define HTSIZE (int)65536

typedef struct			s_room
{
	char				*name;
	int					bfs_level;
	int					x;
	int					y;
	int					num_links;
	char				**links;
	int					out;
	int					in;
}						t_room;

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

typedef struct			s_ant
{
	int					id;
	t_room			*room;
	//ptr to link struct
}						t_ant;

typedef	unsigned short int t_thindex;

t_htable				*g_htable[HTSIZE];
// unsigned char 			g_rand8[256];


//init functions
char			**ft_file_parse(char **split);
int				ft_file_checker(char **split,int all);
int				ft_val_ant(char *split);
int				ft_val_bond(char **split);
int				ft_val_room(char **split);
int				ft_val_coords(char **split, int i);
char			***ft_val_links(char **split, int i, int all);
int				ft_word_counter(char const *s, char c);
void			ft_exit(char *str);
void			ft_prng(unsigned int seed);
int				ft_check_room(char **split, int i);
char			**ft_swap_links(char **str, char **link);
int				ft_val_links2(char **split, int j, int i, char **links);
void			ft_set_links(char ***links, int i, int all);

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

/*
** FUNCS FOR BFS
*/

void		ft_print_bfs(void);

/*
** FUNCS FOR SET WAYS
*/

typedef struct			s_path
{
	char				*room_name;
	int					ant_quantity;
	int					path_length;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

void		ft_del_useless_links(char *data);
int			ft_manage_way(char *data);
int			ft_count_output(char *data);
int			ft_count_input(char *data);
void		ft_output_fork(char *data);
int			ft_manage_output_fork(char *data);
void		ft_delete_output_fork(t_room *room);
t_room		*ft_find_suitable_link_down(t_room *room);

t_room		*ft_find_suitable_link_up(t_room *room);
void		ft_path_forming(int ants);
t_path		*ft_create_path(t_room *room, int length, int ants);
t_path		*ft_create_path_element(t_room *room, int ants, int length);

/*
** FUNCS FOR INPUT FORKS
*/
void    ft_input_fork(char *data);
int ft_find_good_link(char *data);

#endif