/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simply.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:40:47 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/29 17:46:19 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poly.h"

float *simply(float *elem1, float *elem2, int e1, int e2)
{
	int	i;

	i = -1;
	if (e1 >= e2)
	{
		while (++i <= e2)
			elem1[i] = elem1[i] + (-1 * elem2[i]);
		return (elem1);
	}
	else
	{
		while (++i <= e1)
		{
			elem2[i] = elem2[i] + (-1 * elem1[i]);
			elem2[i] *= -1;
		}
		while (++i <= e2)
		{
			if (elem2[i] != 0)
				elem2[i] *= -1;
		}
		return (elem2);
	}
}
