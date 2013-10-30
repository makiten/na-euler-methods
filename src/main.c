/*********************************************************
 ** MAIN EXECUTABLE (main.c)				**
 *********************************************************
 ** @name	main.c					**
 ** @header						**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** Main executable for Euler approximations.		**
 **							**
 *********************************************************/

#include "explicit_euler.h"
#include "implicit_euler.h"

int main (int argc, char** argv) {
	float *x,*x0,*t, interval[2], h;

	int i;
	long int n;

	/* Allow user to input intervals and step size */
	char buffer[100], *bufferEof;

	/* Set the h value */
	printf("Please input your step size (h): ");
	fgets(buffer, sizeof(buffer), stdin);
	h = strtof(buffer, &bufferEof);
	printf("\n%f\n\n", h);
	/* If the user input a bad value, make them repeat until it's correct. */
	while (h <= 0) {
		printf("Incorrect value for h. Please try again:\n");
		fgets(buffer, sizeof(buffer), stdin);
		h = strtof(buffer, &bufferEof);
	}

	/* Set up the interval */
	printf("Please set your lower bound for the interval: \n");
	fgets(buffer, sizeof(buffer), stdin);
	interval[0] = strtof(buffer, &bufferEof);

	printf("Please set your upper bound for the interval: \n");
	fgets(buffer, sizeof(buffer), stdin);
	interval[1] = strtof(buffer, &bufferEof);
	if (interval[1] < interval[0]) {
		float temp;
		temp = interval[0];
		interval[0] = interval[1];
		interval[1] = temp; 
	}

	/* Now we can set n--the number of elements in the arrays */
	n = 1 + ((interval[1] - interval[0]) / h);

	/* Setting up t values */
	t = malloc(n * sizeof(float));
	for (i=0; i <= n; i++) {
		*(t + i) = i * h;
	}

	/* Build sequence */
	x0 = malloc(6 * sizeof(float));
	*x0 = 0.207276642323;
	*(x0 + 1) = 1;
	*(x0 + 2) = 1;
	*(x0 + 3) = 1;
	*(x0 + 4) = 0;
	*(x0 + 5) = 1;
	for (i=0; i < 6; i++) {
		x = get_explicit_euler_seqn (i, t, *(x0+i), h, n);

		addtolog("euler.log", i, t, x, h, n);
		/* Print output */
/*
		printf("With our x', we will apply Forward Euler up to n=%ld.\n", n);
		printf("With a step size of %f, our values are:\n\n", h);
		printf("---------------------------------------------------------------------------------\n");
		printf("| y_n\t| t_n\t\t| Approx. value\t\t| Exact value\t\t\t|\n");
		printf("---------------------------------------------------------------------------------\n");
		for (j=0; j < n; j++) {
			printf("| y_%d\t|  %*.4f\t| %*.2f\t| %*.2f\t\t|\n",
				j,
				6,*(t + j),
				15,*(x + j),
				15,__exact(j, *(t + j))
			);
		}
		printf("---------------------------------------------------------------------------------\n\n");
*/
	}
	printf("\nFile saved to euler.log.\n");
	
	/* Clear up the memory reserved for the sequences and the buffers */
	free(x);
	free(x0);
	free(t);


	return 0;
}

