/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 18:21:14 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/29 17:59:18 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "poly.h"

static void	uni_solu(float *elem)
{
	float result;

	result = (elem[b]) / (2 * (elem[a]));
	result *= -1;
	printf("Discriminant egal a zero.\nUne solution : x = %.0f.\n", result);
}

static void	duo_solu(float *elem, float discri)
{
	t_num	result;

	result.a = (-elem[b] - ft_sqrt(discri)) / (2 * elem[a]);
	result.b = (-elem[b] + ft_sqrt(discri)) / (2 * elem[a]);
	printf("Discriminant positif.\n");
	printf("Deux solution : x1 = %g\tx2 = %g\n", result.a, result.b);
}

static void	duo_solu_ima(float *elem, float discri)
{
	t_num	r;

	r.a = -elem[b] / (2 * elem[a]);
	r.b = (ft_sqrt(-discri)) / (2 * elem[a]);
	printf("Discriminant negatif.\n");
	if (r.b != 1)
	{
		printf("Deux solution complex : ");
		printf("x1 = %g + %gi\tx2 = %g - %gi\n", r.a, r.b, r.a, r.b);
	}
	else
		printf("Deux solution complex : x1 = %g + i\tx2 = %g - i\n", r.a, r.a);
}

static int	init_degree(int size, float *elem)
{
	int degree;
	int i;

	i = -1;
	while (++i <= size)
		if (elem[i] != 0)
			degree = i;
	printf("Degree : %d\n", degree);
	return (degree);
}

void		solu(float *elem, float discri, int size)
{
	int degree;

	degree = init_degree(size, elem);
	if (degree == 0)
		if (elem[0] == 0)
			printf("Tout les nombres reels sont solutions\n");
		else
			printf("Aucune Solution\n");
	else if (degree == 1)
		printf("x = %g\n", (-elem[c] / elem[b]));
	else if (degree == 2)
	{
		if (discri < 0)
		{
			duo_solu_ima(elem, discri);
		}
		else if (discri == 0)
			uni_solu(elem);
		else
			duo_solu(elem, discri);
	}
	else
		printf("Degree supperieur a 2, le programme ne peut pas trouver de solution\n");
}
