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
	int					flag;
	char				*name;
	int					bfs_level;
	int					x;
	int					y;
	int					num_links;
	char				**links;
}						t_room;

typedef struct			s_htable
{
	t_room			*rooms;
	struct s_htable		*next;
}						t_htable;

typedef struct			s_ant
{
	int					id;
	t_room			*room;
	//ptr to link struct
}						t_ant;

typedef	unsigned short int t_thindex;

t_htable				**g_htable;
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
t_htable		*ft_insert_link(char *room, char *link);
t_htable		*ft_find_data(char *data);
void			ft_create_htable(int len);
void			ft_set_htable(char **split, int len);
void			ft_thprint(void);
void			ft_del_htable(void);

#endif