#include "poly.h"
#include <stdio.h>

float	ft_sqrt(float x)
{
	float	root;
	int	i;

	i = -1;
	root = x / 2;
	while (++i < 10)
	{
		root = (((x / root) + root) / 2);
	}
	return (root);
}

void	duo_solu(float *elem, float discri)
{
	t_num	result;
	
	result.a = (-elem[b] - ft_sqrt(discri)) / (2 * elem[a]);
	result.b = (-elem[b] + ft_sqrt(discri)) / (2 * elem[a]);
	printf("Discriminant positif.\nDeux solution : x1 = %f\tx2 = %f\n", result.a, result.b);
}
