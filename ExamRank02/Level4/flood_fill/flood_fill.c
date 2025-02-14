/* $ > cat test.c$ > gcc flood_fill.c test.c - o test;
	test
	11111111
	10001001
	10010001
	10110001
	11100001

	FFFFFFFF
	F000F00F
	F00F000F
	F0FF000F
	FFF0000F
$ > */
//
// Prototype ONLY to print & "paint" one area of '0' or '1'.
#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	// check limmits horinzontally/vertcally
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
char	**make_area(char **zone, t_point size, t_point begin)
{
	char	**area;
	int		i;
	int		j;

	area = malloc(sizeof(char *) * size.y);
	if (!area)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		area[i] = malloc(size.x + 1);
		if (!area[i])
		{
			while (i >= 0)
			{
				free(area[i]);
				i--;
			}
			free(area);
			return (NULL);
		}
		j = 0;
		while (j < size.x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][size.x] = '\0';
		i++;
	}
	return (area);
}
int	main(void)
{
	t_point	size;
	int		i;
	char	**area;
	t_point	begin;

	/* 	char	*zone[] = {"11111111", "10100001", "10010001", "10001001",
				"11111111"};
		*/
	char *zone[] = {
			"11111111111111111111111111111111111111111111111111111111",
			"10100000000000000000000000000000000000000000000000100001",
			"10010000000000000000000000000000000000000000000001000001",
			"10001000000000000000000000000000000000000000000010000001",
			"10000100000000000000000000000000000000000000000100000001",
			"10000010000000000000000000000000000000000000001000000001",
			"10000001000000000000000000000000000000000000010000000001",
			"10000000100000000000000000000000000000000000100000000001",
			"10000000010000000000000000000000000000000001000000000001",
			"10000000001000000000000000000000000000000010000000000001",
			"10000000000100000000000000000000000000000100000000000001",
			"10000000000010000000000000000000000000001000000000000001",
			"10000000000001000000000000000000000000010000000000000001",
			"10000000000000100000000000000000000000100000000000000001",
			"10000000000000010000000000000000000001000000000000000001",
			"10000000000000001000000000000000000010000000000000000001",
			"10000000000000000100000000000000000100000000000000000001",
			"10000000000000000010000000000000001000000000000000000001",
			"10000000000000000001000000000000010000000000000000000001",
			"10000000000000000000100000000000100000000000000000000001",
			"10000000000000000000010000000001000000000000000000000001",
			"10000000000000000000001000000010000000000000000000000001",
			"10000000000000000000000100000100000000000000000000000001",
			"10000000000000000000000010001000000000000000000000000001",
			"10000000000000000000000001010000000000000000000000000001",
			"10000000000000000000000000101000000000000000000000000001",
			"10000000000000000000000000010100000000000000000000000001",
			"10000000000000000000000000001010000000000000000000000001",
			"10000000000000000000000000000101000000000000000000000001",
			"10000000000000000000000000000010100000000000000000000001",
			"10000000000000000000000000000001010000000000000000000001",
			"10000000000000000000000000000000101000000000000000000001",
			"10000000000000000000000000000000010100000000000000000001",
			"10000000000000000000000000000000001010000000000000000001",
			"10000000000000000000000000000000000101000000000000000001",
			"10000000000000000000000000000000000010100000000000000001",
			"10000000000000000000000000000000000001010000000000000001",
			"10000000000000000000000000000000000000101000000000000001",
			"10000000000000000000000000000000000000010100000000000001",
			"10000000000000000000000000000000000000001010000000000001",
			"11111111111111111111111111111111111111111111111111111111",
	};
	size.x = 57;
	size.y = 40;
	i = 0;
	while (i < size.y)
		printf("%s\n", zone[i++]);
	printf("\n");
	begin.x = 7;
	begin.y = 3;
	area = make_area(zone, size, begin);
	flood_fill(area, size, begin);
	i = 0;
	while (i < size.y)
		printf("%s\n", area[i++]);
	i = 0;
	while (i < size.y)
		free(area[i++]);
	free(area);
	return (0);
}
// a simple/uncomplete version to unsderstand how to fill
// by areas perfectly delimited
/* void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	char	target;
	int		i;
	int		j;

	c = tab[begin.y - 1][begin.x - 1];
	target = 'F';
	if (begin.y > size.y && begin.x > size.x)
		return ;
	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (tab[i][j] == c)
				tab[i][j] = target;
			j++;
			if (tab[i][j] != c)
				break ;
		}
		i++;
	}
}

int	main(void)
{
t_point	size;
int		i;
int		j;
char	**area;
t_point	begin;
char	*zone[] = {"11111111", "10100001", "10010001", "10001001", "11111111"};

size.x = 8;
size.y = 5;
i = 0;
while (i < size.y)
	printf("%s\n", zone[i++]);
printf("\n");
area = malloc(sizeof(char *) * size.y);
if (!area)
{
	free(area);
	return (1);
}

i = 0;
while (i < size.y)
{
	area[i] = malloc(size.x + 1);
	if (!area[i])
	{
		while (i > 0)
			free(area[i--]);
		return (1);
	}
	j = 0;
	while (j < size.x)
	{
		area[i][j] = zone[i][j];
		j++;
	}
	area[i][size.x] = '\0';
	i++;
}

begin.x = 7;
begin.y = 4;
flood_fill(area, size, begin);

i = 0;
while (i < size.y)
	printf("%s\n", area[i++]);
return (0);
}*/