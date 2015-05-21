#include "libft.h"

int	pow_max(char *equ)
{
	int	max;

	max = 0;
	while (*equ)
	{
		if (*equ == '^')
		{
			equ++;
			if (max < ft_atoi(equ))
				max = ft_atoi(equ);
			equ--;
		}
		equ++;
	}
	return (max);
}
