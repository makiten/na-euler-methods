/*********************************************************
 ** APPROXIMATION LIBRARY apprlib.h			**
 *********************************************************
 ** @name	apprlib.h				**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** apprlib.c header file				**
 **							**
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <time.h>

/* @function __exact
 * @param int, float
 * @return float
 * @desc Returns the exact value of the DE solution
 */
float __exact(int, float);

/* @function __x_prime
 * @param int, float, float
 * @return float
 * @desc The true function value (for comparison of Euler methods)
 */
float __x_prime(int, float, float);

/* @function addtolog
 * @param const char*, int, float*, float*, float, int
 * @return void
 * @desc Logs the output to a text file
 */
void addtolog(const char*, int, float*, float*, float, int);
