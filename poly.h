/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:39:16 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 19:39:58 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLY_H
# define POLY_H

enum{c, b, a};

typedef struct	s_num
{
	float		a;
	float		b;
}				t_num;

float			get_discriminant(float *elem);
int				pow_max(char *equ);
float			*simply(float *elem1, float *elem2, int e1, int e2);
void			solu(float *elem, float discri, int size);
float			get_nbr(char *equ, char symb);

#endif
