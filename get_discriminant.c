/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_discriminant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:22:18 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 19:22:21 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poly.h"

float	get_discriminant(float *elem)
{
	float	discri;

	discri = (elem[b] * elem[b]) - (4 * (elem[a] * elem[c]));
	return (discri);
}
