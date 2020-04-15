#include "ft_checkers.h"
/*
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
*/
void	print_argv(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_putstr(argv[argc - 1]);
		ft_putstr("\n");
		argc--;
	}
}
/*
void		print_tree(t_path *p)
{
	if (p->fl)
	{
		printf("%d-", p->adr);
		print_tree(p->fl);
		printf("\n");
	}
	if (p->fr)
	{
		printf("%d-", p->adr);
		print_tree(p->fr);
		printf("\n");
	}
	if (p->bl)
	{
		printf("%d-", p->adr);
		print_tree(p->bl);
		printf("\n");
	}
	if (p->br)
	{
		printf("%d-", p->adr);
		print_tree(p->br);
		printf("\n");
	}
}

void		print_all(t_path **all)
{
	int			i;

	i = 0;
	while (all[i])
	{
		print_tree(all[i]);
		i++;
		ft_putstr("\n\n");
	}
}

void	print_arr(int *arr)
{
	int		i;

	i = 0;
	while (arr[i] != -1)
	{
		ft_putnbr(arr[i]);
		i++;
	}
	//ft_putstr("\n");
}

void	print_list(t_way *ell)
{
	while (ell)
	{
		print_arr(ell->way);
		ft_putstr("\n");
		ell = ell->next;
	}
}

void	print_all(t_all *all)
{
	while (all)
	{
		print_list(all->ell);
		all = all->next;
		ft_putstr("\n");
	}
}

t_all	*make_fake(void)
{
	t_all		*all;
	t_all		*all2;
	t_way		*new;
	t_way		*new2;
	int			ar1[14] = {0, 21, 34, -1};
	int			ar2[14] = {0, 11, -1};

	all = (t_all*)malloc(sizeof(t_all));
	new = (t_way*)malloc(sizeof(t_way));
	all->ell = new;
	all2 = (t_all*)malloc(sizeof(t_all));
	all->next = all2;
	new->way = ar1;
	new2 = (t_way*)malloc(sizeof(t_way));
	new2->way = ar2;
	new->next = new2;
	new2->next = NULL;
	all2->ell = new2;
	all2->next = NULL;
	print_list(new);
	return (all);
}
*/
int		main(int argc, char **argv)
{
	int		wnum;
	t_path	**all_path;
	//t_path	*one;
	//t_all	*all;
	//t_way	**way;

	wnum = ft_check_letters(argc, argv);
	if (argc != 9 || !ft_check_fields(argv) || !wnum)
	{
		ft_putstr("Error\n");
		return (0);
	}
	//print_argv(argc, argv);

	all_path = ft_all_tree(wnum, argv);
	//print_all(all_path);
	//way = ft_allway(wnum, argv);
	//all = make_fake();
	//print_all(all);
	//ft_putstr("qwe");
	//ft_putnbr(wnum);
	return (0);
}
