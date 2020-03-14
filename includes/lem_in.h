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

# define P ((int)10) 

typedef struct s_r_list
{
	char			*name;
	size_t			x;
	size_t			y;
	int				flag;
	struct s_r_list	*next;
}					t_r_list;

typedef struct	s_htable
{
	t_r_list			*rooms;
	struct s_htable	*next;
}				t_htable;

typedef struct		s_dbl_room
{
	size_t				level;
	struct s_dbl_room	**next;
	struct s_dbl_room	**prev;
}					t_dbl_room;


typedef struct s_pipe {
	char	*start;
	char	*end;
} t_pipe;

typedef struct s_room {
	unsigned short	busy;
	int				level;
	int				x;
	int				y;
	char 			*name;
	struct t_room			*prev;
	struct t_room			*next;
} t_room;

typedef struct s_lemin {
	int			ants;
	uint16_t	start;
	uint16_t	end;
	t_pipe		*pipes; //pipes between rooms
	t_room		*rooms; //arrays of rooms
} t_lemin;

t_htable	**g_htable;
size_t		g_htsize;
size_t		g_nbr;

//init functions
int		lem_init(t_lemin *lem);
t_dbl_room *create_dbl_room(char *str);

//parse  functions
int				ants_parse(t_lemin *lem);
int				rooms_parse(t_lemin *lem);
char			**ft_file_parse(char **split);
int				ft_file_checker(char **split, t_r_list **start);
int				ft_val_ant(char *split);
int				ft_val_bond(char **split);
int				ft_val_room(char **split, t_r_list **start);
int				ft_val_links(char **split, int i);
int				ft_word_counter(char const *s, char c);
void			ft_exit(char *str);
void			ft_arrclr(char **arr);

/*
**	FUNC FOR LINKED LIST
*/

t_r_list		*ft_crtrm(char *str, int flag);
t_r_list		*ft_add_push_back(t_r_list *tmp, char **split, int i);
t_r_list		*ft_roomdel(t_r_list **ptr);
void			ft_check_name_coord(t_r_list *ptr);
void			ft_print(t_r_list *tmp);

/*
**	FUNC FOR HASH TABLE
*/

size_t			ft_hash(char *data);
t_htable		*ft_insert_data(t_r_list *room);
t_htable		*ft_find_data(char *data);
void			ft_create_htable(size_t len);
void			ft_set_htable(char **split, size_t len);

#endif