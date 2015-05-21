/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:03:47 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 21:19:08 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "poly.h"

static void		fill_elem(float *elem, char *equ)
{
	int		i;
	int		j;
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
	int		i;
	float	*elem;

	i = -1;
	elem = (float *)malloc(sizeof(float) * pow + 1);
	while (++i < pow)
		elem[i] = 0;
	fill_elem(elem, equ);
	return (elem);
}

static void		polynome(char *equ)
{
	float	*elem1;
	float	*elem2;
	int		size;
	char	**split;

	split = ft_strsplit(equ, '=');
	size = (pow_max(split[0]) > pow_max(split[1])) ?
		pow_max(split[0]) : pow_max(split[1]);
	elem1 = init_elem(pow_max(split[0]), split[0]);
	elem2 = init_elem(pow_max(split[1]), split[1]);
	elem1 = simply(elem1, elem2, pow_max(split[0]), pow_max(split[1]));
	get_reduce(elem1, size);
	solu(elem1, get_discriminant(elem1), size);
}

int				main(int ac, char **av)
{
	(void)ac;
	polynome(av[1]);
	return (1);
}
