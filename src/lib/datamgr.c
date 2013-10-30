/*********************************************************
 ** APPROXIMATION LIBRARY (../lib/datamgr.c)			**
 *********************************************************
 ** @name	../lib/datamgr.c				**
 ** @header	../lib/datamgr.h				**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** Library for approximation methods			**
 **							**
 *********************************************************/
#include <datamgr.h>
#define TOLER 0.00001

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
