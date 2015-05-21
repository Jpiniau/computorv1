#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "poly.h"

static float	get_nbr(char *equ, char symb)
{
	int	size_int;
	int	size_float;
	int	i;
	int	j;
	float	result;
	float	result_float;

	i = 0;
	j = 1;
	size_int = 0;
	size_float = 0;
	while (ft_isdigit(equ[i]))
	{
		size_int++;
		i++;
	}
	if (equ[i] == '.')
	{
		i++;
		while (ft_isdigit(equ[i]))
		{
			size_float++;
			i++;	
		}
	}
	i = -1;
	result = 0;
	result_float = 0;
	while (++i < size_int)
		result = ((equ[i] - '0') * ft_pow(10, size_int - 1 - i)) + result;
	if (size_float > 0)
	{	
		while (++i <= size_int + size_float)
		{
			result_float = ((1 / (float)ft_pow(10, j)) * (equ[i] - '0')) + result_float;
			j++;
		}
	}
	result = result + result_float;
	if (symb == '-')
		result *= -1;
	return (result);
}

static void	fill_elem(float *elem, char *equ)
{
	int	i;
	int	j;
	char	symb;

	symb = '+';
	i = 0;
	while (*equ != '\0')
	{
		if (*equ == '-' || *equ == '+')
			symb = *equ;
		if (ft_isdigit(*equ))
		{
			elem[i] = get_nbr(equ, symb); 
			i++;
			j = 0;
			while (equ[j] && equ[j] != '+' && equ[j] != '-')
				j++;
			equ += j - 1;
		}
		equ++;
	}

}

static float	*init_elem(int pow, char *equ)
{
	int	i;
	float	*elem;

	i = -1;
	elem = (float *)malloc(sizeof(float) * pow + 1);
	while (++i < pow)
		elem[i] = 0;
	fill_elem(elem, equ);
	return (elem);
}

static void	polynome(char *equ)
{
	float	*elem1;
	float	*elem2;
	float	discri;
	int	size;
	char	**split;
	int	degree;
	int	i;

	i = -1;
	(void)equ;
	degree = 0;
	split = ft_strsplit(equ, '=');
	size = (pow_max(split[0]) > pow_max(split[1])) ? pow_max(split[0]) : pow_max(split[1]);
	elem1 = init_elem(pow_max(split[0]), split[0]);
	elem2 = init_elem(pow_max(split[1]), split[1]);
	elem1 = simply(elem1, elem2, pow_max(split[0]), pow_max(split[1]));
	while (++i <= size)
		if (elem1[i] != 0)
			degree = i;
	printf("Degree : %d\n", degree);
	discri = get_discriminant(elem1);
	printf("Discriminant : %f\n", discri);
	solu(elem1, discri, degree);
}

int		main(int ac, char **av)
{
	(void)ac;
	polynome(av[1]);
	return (1);
}
