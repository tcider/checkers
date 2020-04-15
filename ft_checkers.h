#ifndef FT_CHECKERS_H
# define FT_CHECKERS_H

# include <unistd.h>
# include <stdlib.h>
//только для теста
# include <stdio.h>

typedef struct		s_path
{
	struct s_path		*prev;
	struct s_path		*fr;
	struct s_path		*fl;	
	struct s_path		*br;	
	struct s_path		*bl;
	int					adr;
}					t_path;

typedef struct		s_way
{
	struct s_way		*next;
	int					*way;
	int					*bb;
}					t_way;

typedef struct		s_all
{
	char				*str;
	struct s_all		*prev;
}					t_all;

void	print_arr(int *arr);
void	print_list(t_way *ell);

t_way		**ft_allway(int wnum, char **argv);
void		ft_findway(char **brgv, t_way *path, int i, int j);
char		**ft_brgv(char **argv);
int			ft_prev(int *way);
t_way		*ft_makeway(int *bb, int *way);
char		**ft_newbrgv(char **brgv, int *bb, int *way);
char		**ft_setbrgv(char **brgv, int adr, char c);
int			*ft_addadr(int *bb, int adr);
int			ft_getadr(int i, int j);

void		ft_flbranch(t_path *p, int adr, int *bb, char **argv);
void		ft_frbranch(t_path *p, int adr, int *bb, char **argv);
void		ft_blbranch(t_path *p, int adr, int *bb, char **argv);
void		ft_brbranch(t_path *p, int adr, int *bb, char **argv);
int			ft_getladr(int i, int j);
int			ft_arrsize(int *bb);
int			*ft_bb(char **argv, char c);
int			*ft_bbcpy(int *bb);
int			ft_isbb(int i, int j, int *bb);
int			*ft_adrbb(int *bb, int adr);
int			*ft_bbremove(int i, int j, int *bb);
t_path		*ft_one_path(t_path *prev, int adr, int *bb, char **argv);
t_path		**ft_all_tree(int wnum, char **argv);

int			ft_check_letters(int argc, char **argv);
int			ft_check_fields(char **argv);
int			ft_charstr(char *str, char c);
int			ft_strlen(char *str);
void		ft_putstr(char *str);

#endif
