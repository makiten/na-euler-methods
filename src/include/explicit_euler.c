/*********************************************************
 ** EXPLICIT EULER (explicit_euler.c)			**
 *********************************************************
 ** @name	explicit_euler.c			**
 ** @header	explicit_euler.h			**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** A series of functions for producing sequence	**
 ** approximations of ODEs using forward Euler.		**
 **							**
 *********************************************************/
#include <explicit_euler.h>

float* get_explicit_euler_seqn(int s, float* t, float x0, float h, int n) {
	float *x;
	x = malloc(n * sizeof(float));
	*x = x0;
	explicit_euler(s, t, x, h, n);

	return x;
}

void explicit_euler(int s, float* t, float* x, float h, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		*(x + (i + 1)) = *(x + i) + (h * __x_prime(s, *(t + i), *(x + i)));
	}
}

