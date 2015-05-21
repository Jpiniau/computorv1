
#include "poly.h"

float	get_discriminant(float *elem)
{
	float	discri;

	discri = (elem[b] * elem[b]) - (4 * (elem[a] * elem[c]));
	return (discri);
}
