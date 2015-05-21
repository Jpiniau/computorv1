/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 18:21:14 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 18:41:03 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "poly.h"

static void	uni_solu(float *elem)
{
	float result;

	result = (elem[b]) / (2 *(elem[a]));
	result *= -1;
	printf("Discriminant egal a zero.\nUne solution : x = %f.\n", result);
}

static void	duo_solu(float *elem, float discri)
{
	t_num	result;

	result.a = (-elem[b] - ft_sqrt(discri)) / (2 * elem[a]);
	result.b = (-elem[b] + ft_sqrt(discri)) / (2 * elem[a]);
	printf("Discriminant positif.\nDeux solution : x1 = %f\tx2 = %f\n", result.a, result.b);
}

void		solu(float *elem, float discri, int degree)
{
	if (degree == 0)
	{
		if (elem[0] == 0)
			printf("Tout les nombres reels sont solutions\n");
		else
			printf("Aucune Solution\n");
	}
	else if (degree == 1)
		printf("x = %f\n", (-elem[c] / elem[b]));
	else if (degree == 2)
	{
		if (discri < 0)
			printf("Discriminant strictement negatif.\nPas de solution dans les reel");
		else if (discri == 0)
			uni_solu(elem);
		else
			duo_solu(elem, discri);
	}
	else
		printf("Aucune solution dans R\n");
}