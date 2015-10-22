/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:39:16 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/22 13:41:15 by jpiniau          ###   ########.fr       */
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
void			get_reduce(float *elem, int size);
int				verify(char *equ);
int				go_c(char *equ, int part);

#endif
