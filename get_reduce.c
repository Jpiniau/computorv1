/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:47:59 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/29 18:05:02 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	print_r(int i, float *elem, int first)
{
	if (i == 0 && elem[i] != 0)
	{
		printf("%g * X^%d", elem[0], i);
		first = 1;
	}
	else
	{
		if (elem[i] >= 0)
		{
			if (first)
				printf(" + ");
			printf("%g * X^%d", elem[i], i);
			first = 1;
		}
		else if (elem[i] < 0)
		{
			printf(" - %g * X^%d", elem[i] * -1, i);
			first = 1;
		}
	}
	return (first);
}

void		get_reduce(float *elem, int size)
{
	int	i;
	int first;

	i = -1;
	first = 0;
	printf("Forme reduite :");
	while (++i <= size)
	{
		first = print_r(i, elem, first);
	}
	printf(" = 0\n");
}
