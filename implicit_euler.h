/*********************************************************
 ** IMPLICIT EULER (implicit_euler.h)			**
 *********************************************************
 ** @name	implicit_euler.h			**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** implicit_euler.c header file			**
 **							**
 *********************************************************/
#include "apprlib.h"

/* @function 
 * @param int, float*, float, float, int
 * @return float*
 * @desc Produces a sequence using the implicit Euler method
 */
float* get_implicit_euler_seqn(int, float*, float, float, int);
/* @function implicit_euler
 * @param int, float, float*, float, int
 * @return void
 * @desc
 */
void implicit_euler(int, float*, float*, float, int);
