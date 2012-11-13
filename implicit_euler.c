/*********************************************************
 ** IMPLICIT EULER (implicit_euler.c)			**
 *********************************************************
 ** @name	implicit_euler.c			**
 ** @header	implicit_euler.h			**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** A series of functions for producing sequence	**
 ** approximations of ODEs using backward Euler.	**
 **							**
 *********************************************************/
#include "implicit_euler.h"

float* get_implicit_euler_seqn(int s, float* t, float x0, float h, int n) {
	float *x;
	x = malloc(n * sizeof(float));
	*x = x0;
	implicit_euler(s, t, x, h, n);

	return x;
}

void implicit_euler(int s, float* t, float* x, float h, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		*(x + (i + 1)) = *(x + i) + (h * __x_prime(s, *(t + (i + 1)), *(x + (i + 1))));
	}

}
