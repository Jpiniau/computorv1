#include "poly.h"

float *simply(float *elem1, float *elem2, int e1, int e2)
{
	int	i;

	i = -1;
	if (e1 > e2)
	{
		while (++i <= e2)
			elem1[i] = elem1[i] + (-1 * elem2[i]);
		return (elem1);
	}
	else
	{
		while (++i <= e1)
			elem2[i] = elem2[i] + (-1 * elem1[i]);
		return (elem2);
	}
}
