/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:07:32 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/11 21:13:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
#include <stdint.h>
# include <unistd.h>
#include <stdlib.h> //DELETE THIS
#include <stdio.h> //DELETE THIS
#include "libft.h"

# define READ	4096

typedef struct		s_room
{
    void			*name;
    int				x;
	int				y;
    struct s_tree	*right;
    struct s_tree	*left;
}					t_room;

typedef struct s_r_list {
	char *name;
	int x;
	int y;
	struct s_r_list *next;
	struct s_r_list *prev;
} t_r_list;

typedef struct s_dbl_room {
	size_t size;
	t_r_list *head;
	t_r_list *tail;
} t_dbl_room;


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

//init functions
int		lem_init(t_lemin *lem);
t_dbl_room *create_dbl_room(void);

//parse  functions
int		ants_parse(t_lemin *lem);
int		rooms_parse(t_lemin *lem);
char	**ft_file_parse(char **split);
int		ft_file_checker(char **split);
int		ft_val_ant(char *split);
int		ft_val_bond(char **split);
int		ft_val_room(char **split);
int		ft_val_links(char **split, int i);
int	    ft_word_counter(char const *s, char c);


void	ft_arrclr(char **arr);

#endif