#include <stdio.h>
#include "poly.h"

void	uni_solu(float *elem)
{
	float result;

	result = (elem[b]) / (2 *(elem[a]));
	result *= -1;
	printf("Discriminant egal a zero.\nUne solution : x = %f.\n", result);
}
