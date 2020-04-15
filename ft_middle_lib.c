#include "ft_checkers.h"

t_way		**ft_allway(int wnum, char **argv)
{
	t_way		**all;
	t_way		*new;
	int			i;
	int			j;
	int			k;
	char		**brgv;

	all = (t_way**)malloc(sizeof(t_way*) * wnum);
	k = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_charstr("Ww", argv[i][j]))
			{
				brgv = ft_brgv(argv);
				new = (t_way*)malloc(sizeof(t_way));
				all[k] = new;
				new->bb = (int*)malloc(sizeof(int) * 13);
				new->bb[0] = -1;
				new->way = (int*)malloc(sizeof(int) * 14);
				new->way[0] = -1;
				ft_findway(brgv, new, i - 1, j);
				//print_list(new);
				k++;
			}
			j++;
		}
		i++;
	}
	return (all);
}

void		ft_findway(char **brgv, t_way *path, int i, int j)
{
	t_way		*new;

	path->way = ft_addadr(path->way, ft_getadr(i, j));
	brgv[i][j] = '.';
	if (i <= 5 && j >= 2)
	{
		//if (brgv[i + 2][j - 2] == '.' && ft_charstr("Bb", brgv[i + 1][j - 1]))
		//{
		//	brgv[i + 1][j - 1] = '.';
		//	path->bb = ft_addadr(path->bb, ft_getadr(i + 1, j - 1));
		//	ft_findway(brgv, path, i + 2, j - 2);
		//}
	}
	if (brgv[i + 2][j + 2] && brgv[i + 2][j + 2] == '.' && ft_charstr("Bb", brgv[i + 1][j + 1]))
	{
		brgv[i + 1][j + 1] = '.';
		path->bb = ft_addadr(path->bb, ft_getadr(i + 1, j + 1));
		ft_findway(brgv, path, i + 2, j + 2);
	}
	if (ft_prev(path->way) == -1)
		return ;
	brgv = ft_newbrgv(brgv, path->bb, path->way);
	new = ft_makeway(path->bb, path->way);
	path->next = new;
	ft_findway(brgv, new, ft_prev(path->way) / 8, ft_prev(path->way) % 8);
}

char		**ft_brgv(char **argv)
{
	int			i;
	int			j;
	char		**brgv;

	brgv = (char**)malloc(sizeof(char*) * 8);
	i = 1;
	while (argv[i])
	{
		j = 0;
		brgv[i - 1] = (char*)malloc(sizeof(char) * 9);
		while (argv[i][j])
		{
			brgv[i - 1][j] = argv[i][j];
			j++;
		}
		brgv[i - 1][j] = '\0';
		i++;
	}
	return (brgv);
}

int			ft_prev(int *way)
{
	int			i;

	i = 0;
	while (way[i] != -1)
		i++;
	if (i >= 2)
		return (way[i - 2]);
	else
		return (-1);
}

t_way		*ft_makeway(int *bb, int *way)
{
	t_way		*new;
	int			i;

	new = (t_way*)malloc(sizeof(t_way));
	i = 0;
	while (bb[i])
		i++;
	bb[i - 1] = -1;
	i = 0;
	while (way[i])
		i++;
	way[i - 1] = -1;
	new->bb = bb;
	new->way = way;
	new->next = NULL;
	return (new);
}

char		**ft_newbrgv(char **brgv, int *bb, int *way)
{
	int			i;

	i = 0;
	while (bb[i] != -1)
		i++;
	brgv = ft_setbrgv(brgv, bb[i - 1], 'b');
	i = 0;
	while (way[i] != -1)
		i++;
	brgv = ft_setbrgv(brgv, way[i - 1], '0');
	return (brgv);
}

char		**ft_setbrgv(char **brgv, int adr, char c)
{
	int			i;
	int			j;

	i = adr / 8;
	j = adr % 8;
	brgv[i][j] = c;
	return (brgv);
}

int			*ft_addadr(int *bb, int adr)
{
	int			i;

	i = 0;
	while (bb[i] != -1)
		i++;
	bb[i] = adr;
	bb[i + 1] = -1;
	return (bb);
}

int			ft_getadr(int i, int j)
{
	return (i * 8 + j);
}

void ft_putchar(char a)
{
	printf("%c", a);
}
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
void	print_arr(int *arr)
{
	int		i;

	i = 0;
	while (arr[i] != -2)
	{
		ft_putnbr(arr[i]);
		ft_putchar('-');
		i++;
	}
	ft_putchar('\n');
}

void		print_adrbb(int *bb)
{
	int			i;

	i = 0;
	while (bb[i] != -2)
		i++;
	while (bb[i] != -3)
	{
		ft_putnbr(bb[i]);
		ft_putchar('-');
		i++;
	}
}

int		ft_way_len(t_path *p)
{
	int			i;

	i = 0;
	while (p)
	{
		p = p->prev;
		i++;
	}
	return (i);
}

char	*ft_way_str(t_path *p)
{
	char		*str;
	int			n;
	int			k;
	int			*tmp;
	int			i;
	int			j;

	n = 0;
	str = (char*)malloc(sizeof(char) * 39);
	tmp = (int*)malloc(sizeof(int) * 13);
	while (p)
	{
		tmp[n] = p->adr;
		p = p->prev;
		n++;
	}
	k = 0;
	while (n >= 1)
	{
		i = tmp[n - 1] / 8 + 1;
		j = tmp[n - 1] % 8;
		str[k] = i + '0';
		k++;
		str[k] = j + 'A';
		k++;
		n--;
	}
	str[k] = '\0';
	return (str);
}

t_all		*print_tree(t_path *p, t_all *a)
{
	t_all		*tmp;

	tmp = NULL;
	if (p->fl)
		print_tree(p->fl, a);
	if (p->fr)
		print_tree(p->fr, a);
	if (p->bl)
		print_tree(p->bl, a);
	if (p->br)
		print_tree(p->br, a);
	if (!p->fl && !p->fr && !p->bl && !p->br)
	{
		tmp = (t_all*)malloc(sizeof(t_all));
		tmp->str = ft_way_str(p);
		tmp->prev = a;
		//ft_putstr(tmp);
	}
	return (tmp);
}

t_all		*ft_maxstr(t_all *a)
{
	int			i;
	t_all		*tmp;
	int			n;

	i = 0;
	while (a)
	{
		n = ft_strlen(a->str);
		if (n > i)
		{
			i = n;
			tmp = a;
		}
		a = a->prev;
	}
	return (tmp);
}

void		print_all(t_path **all)
{
	int			i;
	//char		*str;
	t_all		*a;

	i = 0;
	while (all[i])
	{
		a = print_tree(all[i], NULL);
		a = ft_maxstr(a);
		ft_putstr(a->str);
		i++;
	}
}

t_path		**ft_all_tree(int wnum, char **argv)
{
	t_path		**all;
	int			i;
	int			j;
	int			k;
	int			*bb;

	i = 1;
	k = 0;
	all = (t_path**)malloc(sizeof(t_path*) * (wnum + 1));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_charstr("Ww", argv[i][j]))
			{
				bb = ft_bb(argv, argv[i][j]);
				argv[i][j] = '.';
				all[k] = ft_one_path(NULL, ft_getladr(i, j), bb, argv);
				print_tree(all[k], NULL);
				k++;
			}
			j++;
		}
		i++;
	}
	all[k] = NULL;
	print_all(all);
	return (all);
}

t_path		*ft_one_path(t_path *prev, int adr, int *bb, char **argv)
{
	t_path		*p;
	
	//print_arr(bb);
	//ft_putnbr(ft_arrsize(bb));
	p = (t_path*)malloc(sizeof(t_path));
	p->prev = prev;
	p->adr = adr;
	//p->bb = bb;
	//bb = ft_adrbb(bb, adr);
	ft_flbranch(p, adr, bb, argv);
	ft_frbranch(p, adr, bb, argv);
	//ft_blbranch(p, adr, bb, argv);
	//ft_brbranch(p, adr, bb, argv);
	return (p);
}

void		ft_flbranch(t_path *p, int adr, int *bb, char **argv)
{
	int			i;
	int			j;

	i = adr / 8 + 1;
	j = adr % 8;
	if (i <= 6 && j >= 2)
	{
	if (argv[i + 2][j - 2] == '.' && ft_isbb(i + 1, j - 1, bb))
	{
		bb = ft_bbremove(i + 1, j - 1, bb);
		p->fl = ft_one_path(p, ft_getladr(i + 2, j - 2), bb, argv);
	}
	}
	else
		p->fl = NULL;
}

void		ft_frbranch(t_path *p, int adr, int *bb, char **argv)
{
	int			i;
	int			j;
	int			*aa;

	i = adr / 8 + 1;
	j = adr % 8;
	if (i <= 6 && j <= 5)
	{
	if (argv[i + 2][j + 2] == '.' && ft_isbb(i + 1, j + 1, bb))
	{
		if (p->fl || p->bl || p->br)
		{
			aa = ft_bbcpy(bb);
			aa = ft_bbremove(i + 1, j + 1, aa);
			p->fr = ft_one_path(p, ft_getladr(i + 2, j + 2), aa, argv);
		}
		else
		{
			bb = ft_bbremove(i + 1, j + 1, bb);
			p->fr = ft_one_path(p, ft_getladr(i + 2, j + 2), bb, argv);
		}
	}
	}
	else
		p->fr = NULL;
}

void		ft_brbranch(t_path *p, int adr, int *bb, char **argv)
{
	int			i;
	int			j;
	int			*aa;

	i = adr / 8 + 1;
	j = adr % 8;
	if (bb[0] == 'W' && argv[i - 2][j + 2] == '.' && ft_isbb(i - 1, j + 1, bb))
	{
		if (p->fl || p->bl || p->fr)
		{
			aa = ft_bbcpy(bb);
			aa = ft_bbremove(i - 1, j + 1, aa);
			p->br = ft_one_path(p, ft_getladr(i - 2, j + 2), aa, argv);
		}
		else
		{
			bb = ft_bbremove(i - 1, j + 1, bb);
			p->br = ft_one_path(p, ft_getladr(i - 2, j + 2), bb, argv);
		}
	}
	else
		p->br = NULL;
}

void		ft_blbranch(t_path *p, int adr, int *bb, char **argv)
{
	int			i;
	int			j;
	int			*aa;

	i = adr / 8 + 1;
	j = adr % 8;
	if (bb[0] == 'W' && argv[i - 2][j - 2] == '.' && ft_isbb(i - 1, j - 1, bb))
	{
		if (p->fl || p->br || p->fr)
		{
			aa = ft_bbcpy(bb);
			aa = ft_bbremove(i - 1, j - 1, aa);
			p->bl = ft_one_path(p, ft_getladr(i - 2, j - 2), aa, argv);
		}
		else
		{
			bb = ft_bbremove(i - 1, j - 1, bb);
			p->bl = ft_one_path(p, ft_getladr(i - 2, j - 2), bb, argv);
		}
	}
	else
		p->bl = NULL;
}
int			*ft_bbremove(int i, int j, int *bb)
{
	int			n;

	n = 0;
	while (bb[n] != -2)
	{
		if (ft_getladr(i, j) == bb[n])
			bb[n] = -1;
		n++;
	}
	return (bb);
}

int			ft_isbb(int i, int j, int *bb)
{
	int			n;

	n = 0;
	while (bb[n] != -2)
	{
		if (ft_getladr(i, j) == bb[n])
			return (1);
		n++;
	}
	return (0);
}

int			*ft_bbcpy(int *bb)
{
	int			i;
	int			*aa;

	i = 0;
	aa = (int*)malloc(sizeof(int) * 14);
	while (bb[i] != -2)
	{
		aa[i] = bb[i];
		i++;
	}
	aa[i] = -2;
	return (aa);
}

int			*ft_bb(char **argv, char c)
{
	int			i;
	int			j;
	int			k;
	int			*bb;

	i = 1;
	k = 1;
	bb = (int*)malloc(sizeof(int) * 14);
	bb[0] = c;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_charstr("Bb", argv[i][j]))
			{
				bb[k] = ft_getladr(i, j);
				k++;
			}
			j++;
		}
		i++;
	}
	bb[k] = -2;
	//bb[k + 1] = -3;
	return (bb);
}

//
int			*ft_adrbb(int *bb, int adr)
{
	int			i;

	i = 0;
	while (bb[i] != -3)
		i++;
	bb[i] = adr;
	bb[i + 1] = -3;
	return (bb);
}


int			ft_getladr(int i, int j)
{
	return ((i - 1) * 8 + j);
}
