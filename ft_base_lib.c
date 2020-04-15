#include "ft_checkers.h"

int		ft_check_letters(int argc, char **argv)
{
	int		j;
	int		w;
	int		b;

	w = 0;
	b = 0;
	while (argc > 1)
	{
		if (ft_strlen(argv[argc - 1]) != 8)
			return (0);
		j = -1;
		while (argv[argc - 1][++j])
		{
			if (!ft_charstr("wWbB.", argv[argc - 1][j]))
				return (0);
			if (ft_charstr("Ww", argv[argc - 1][j]))
				w++;
			if (ft_charstr("Bb", argv[argc - 1][j]))
				b++;
		}
		argc--;
	}
	if (b == 0 || b > 12 || w > 12)
		return (0);
	return (w);
}

int		ft_check_fields(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j % 2 == i % 2)
				if (argv[i][j] != '.')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_charstr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}
