#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <time.h>

float* get_explicit_euler_seqn(int, float*, float, float, int);
float* get_implicit_euler_seqn(int, float*, float, float, int);
void explicit_euler(int, float*, float*, float, int);
void implicit_euler(int, float*, float*, float, int);
float __exact(int, float);
float __x_prime(int, float, float);
void addtolog(const char*, int, float*, float*, float, int);
