/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:47:59 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 20:16:31 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	get_reduce(float *elem, int size)
{
	int	i;

	i = -1;
	printf("Forme reduite :");
	while (++i <= size)
	{
		if (i == 0)
			printf("%g * X^0", elem[0]);
		else
			if (elem[i] > 0)
				printf(" + %g * X^%d", elem[i], i);
			else if (elem[i] < 0)
				printf(" - %g * X^%d", elem[i] * -1, i);
	}
	printf("\n");
}
