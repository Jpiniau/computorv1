/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:01:09 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 19:38:39 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "poly.h"

static void		init(char *equ, int *size_int, int *size_float)
{
	int i;

	i = 0;
	while (ft_isdigit(equ[i]))
	{
		(*size_int)++;
		i++;
	}
	if (equ[i] == '.')
	{
		i++;
		while (ft_isdigit(equ[i]))
		{
			(*size_float)++;
			i++;
		}
	}
}

static float	get_result(int size_int, int size_float, char *equ)
{
	int		i;
	int		j;
	float	result;
	float	result_float;
	float	tmp;

	result = 0;
	result_float = 0;
	i = -1;
	j = 1;
	while (++i < size_int)
		result = ((equ[i] - '0') * ft_pow(10, size_int - 1 - i)) + result;
	if (size_float > 0)
	{
		while (++i <= size_int + size_float)
		{
			tmp = ((1 / (float)ft_pow(10, j)) * (equ[i] - '0'));
			result_float = tmp + result_float;
			j++;
		}
	}
	result = result + result_float;
	return (result);
}

float			get_nbr(char *equ, char symb)
{
	int		size_int;
	int		size_float;
	float	result;

	size_int = 0;
	size_float = 0;
	init(equ, &size_int, &size_float);
	result = get_result(size_int, size_float, equ);
	if (symb == '-')
		result *= -1;
	return (result);
}
