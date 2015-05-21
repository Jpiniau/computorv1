#ifndef POLY_H
# define POLY_H

enum{c, b, a};

typedef struct	s_num
{
	float	a;
	float	b;
}		t_num;

float	get_discriminant(float *elem);
void	uni_solu(float *elem);
void	duo_solu(float *elem, float discri);
int	pow_max(char *equ);
float	*simply(float *elem1, float *elem2, int e1, int e2);

#endif
