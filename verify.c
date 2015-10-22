/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 12:56:23 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/22 16:11:37 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "poly.h"

char	*jmpspace(char *str)
{
	while (*str == ' ' && *str != '\0')
	{
		str++;
	}
	return (str);
}

int		go_pow(char *equ)
{
	equ++;
	equ = jmpspace(equ);
	if (*equ == 'X' || *equ == 'x')
	{
		equ++;
		equ = jmpspace(equ);
		if (*equ == '^')
		{
			equ++;
			equ = jmpspace(equ);
			if (ft_isdigit(*equ))
				return (go_c(equ, 0));
		}
	}
	return (0);
}

int		go_c(char *equ, int part)
{
	equ++;
	equ = jmpspace(equ);
	if (*equ == '\0')
		return (1);
	else if (ft_isdigit(*equ))
		return (go_c(equ, part));
	else if (*equ == '.' && part != 1)
	{
		equ++;
		if (ft_isdigit(*equ))
			return (go_c(equ, 1));
	}
	else if (*equ == '*')
	{
		return (go_pow(equ));
	}
	else if (*equ == '+' || *equ == '-')
	{
		equ++;
		return (verify(equ));
	}
	return (0);
}

int		verify(char *equ)
{
	static int sym;

	equ = jmpspace(equ);
	if (ft_isdigit(*equ))
	{
		sym = 0;
		return (go_c(equ, 0));
	}
	else if ((*equ == '+' || *equ == '-') && sym != 1)
	{
		sym = 1;
		equ++;
		return (verify(equ));
	}
	else
	{
		sym = 0;
		return (0);
	}
}
