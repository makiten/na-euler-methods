/*********************************************************
 ** EULER METHOD PROCESSES (euler.c)			**
 *********************************************************
 ** @name	euler.c					**
 ** @header	euler.h					**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** A series of functions for producing sequence	**
 ** approximations of ODEs using Euler's methods	**
 **							**
 *********************************************************/
#include "euler.h"
#define TOLER 0.00001

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

/* @function 
 * @param int, float*, float, float, int
 * @return float*
 * @desc Produces a sequence using the explicit Euler method
 */
float* get_explicit_euler_seqn(int s, float* t, float x0, float h, int n) {
	float *x;
	x = malloc(n * sizeof(float));
	*x = x0;
	explicit_euler(s, t, x, h, n);

	return x;
}

/* @function explicit_euler
 * @param int, float*, float*, float, int
 * @return void
 * @desc
 */
void explicit_euler(int s, float* t, float* x, float h, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		*(x + (i + 1)) = *(x + i) + (h * __x_prime(s, *(t + i), *(x + i)));
	}
}

/* @function 
 * @param int, float*, float, float, int
 * @return float*
 * @desc Produces a sequence using the implicit Euler method
 */
float* get_implicit_euler_seqn(int s, float* t, float x0, float h, int n) {
	float *x;
	x = malloc(n * sizeof(float));
	*x = x0;
	implicit_euler(s, t, x, h, n);

	return x;
}

/* @function implicit_euler
 * @param int, float, float*, float, int
 * @return void
 * @desc
 */
void implicit_euler(int s, float* t, float* x, float h, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		*(x + (i + 1)) = *(x + i) + (h * __x_prime(s, *(t + (i + 1)), *(x + (i + 1))));
	}

}

/* @function __exact
 * @param int, float
 * @return float
 * @desc Returns the exact value of the DE solution
 */
float __exact(int s, float t) {
	if (s < 0 || s > 5) {
		s = 0;
	}
	float val;
	switch(s) {
		case 0:
			val = (6 * exp(t - 1)) - powf(t, 2) - (2 * t) - 2;
		break;
		case 1:
			val = exp(-2 * t);
		break;
		case 2:
			val = t + expf((-1 * powf(t, 2))/2);
		break;
		case 3:
			val = exp((-1 * powf(t, 2))/2);
		break;
		case 4:
			val = sinf(t);	
		break;
		case 5:
			val = sinf(t) + cosf(t);
		break;
	}
	return val;
}

/* @function __x_prime
 * @param int, float, float
 * @return float
 * @desc The true function value (for comparison of Euler methods)
 */
float __x_prime(int s, float t, float x) {
	if (s < 0 || s > 5) {
		s = 0;
	}
	float val;
	switch(s) {
		case 0:
			val = x + powf(t, 2);
		break;
		case 1:
			val = -2 * x;
		break;
		case 2:
			val = powf(t,2) - (t * x) + 1;
		break;
		case 3:
			val = -(x * t);
		break;
		case 4:
			val = csqrtf(1 - powf(x,2));
		break;
		case 5:
			val = x - (2 * sinf(t));
		break;
	}
	return val;
}

/* @function addtolog
 * @param const char*, int, float*, float*, float, int
 * @return void
 * @desc Logs the output to a text file
 */
void addtolog(const char* f, int s, float* t, float* x, float h, int n) {
	FILE *fp;
	int i,is_accurate;
	time_t rawtime;
	struct tm * timeinfo;
	float exactval,errorval;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	/* */
	fp = fopen(f, "a+");
	is_accurate = 0;

	/* Print output */
	fprintf(fp, "************************\n");
	fprintf(fp, "* PROBLEM #%d           *\n", s);
	fprintf(fp, "************************\n");
	fprintf(fp, "Output displayed at: %s\n\n", asctime(timeinfo));
	fprintf(fp, "We will apply Forward Euler up to n=%d, with a step size of %f.\n\n", n, h);
	fprintf(fp, "-------------------------------------------------------------------------------------------------\n");
	fprintf(fp, "| y_n\t| t_n\t\t| Approx. value\t\t| Exact value\t\t| Error\t\t\t|\n");
	fprintf(fp, "-------------------------------------------------------------------------------------------------\n");
	for (i=0; i < n; i++) {
		exactval = __exact(s, *(t + i));
		errorval = sqrtf( powf( (*(x + i) - exactval) , 2) );
		fprintf(fp, "| y_%d\t|  %*.4f\t| %*.12f\t| %*.12f\t| %*.12f\t|\n",
			i,
			6,*(t + i),
			15,*(x + i),
			15,exactval,
			15,errorval
		);
		if ( (i == n - 1) && (errorval < TOLER) ) {
			 is_accurate = 1;
		}
	}
	fprintf(fp, "-------------------------------------------------------------------------------------------------\n\n");
	if (is_accurate) {
		fprintf(fp, "This step size meets our desired level of accuracy.\n");
	}

	fclose(fp);
}
