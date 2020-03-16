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

typedef struct			s_r_list
{
	char				*name;
	size_t				x;
	size_t				y;
	int					flag;
	int					len;
	char				**next;
}						t_r_list;

typedef struct			s_htable
{
	t_r_list			*rooms;
	struct s_htable		*next;
}						t_htable;

typedef struct			s_ant
{
	int					id;
	t_r_list			*room;
	//ptr to link struct
}						t_ant;

typedef	unsigned short int t_thindex;

t_htable				**g_htable;
// unsigned char 			g_rand8[256];


//init functions
char			**ft_file_parse(char **split);
int				ft_file_checker(char **split);
int				ft_val_ant(char *split);
int				ft_val_bond(char **split);
int				ft_val_room(char **split);
int				ft_val_links(char **split, int i);
int				ft_word_counter(char const *s, char c);
void			ft_exit(char *str);
void			ft_prng(unsigned int seed);
int				ft_check(char **split, size_t i);

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
t_htable		*ft_insert_room(t_r_list *room);
t_htable		*ft_find_data(char *data);
void			ft_create_htable(size_t len);
void			ft_set_htable(char **split, size_t len);
void			ft_thprint(void);

#endif