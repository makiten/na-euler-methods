/*********************************************************
 ** EXPLICIT EULER (explicit_euler.h)			**
 *********************************************************
 ** @name	explicit_euler.h			**
 ** @email	makiten@neonnightrider.com		**
 ** @description					**
 ** explicit_euler.c header file			**
 **							**
 *********************************************************/
#include <datamgr.h>

/* @function 
 * @param int, float*, float, float, int
 * @return float*
 * @desc Produces a sequence using the explicit Euler method
 */
float* get_explicit_euler_seqn(int, float*, float, float, int);
/* @function explicit_euler
 * @param int, float*, float*, float, int
 * @return void
 * @desc
 */
void explicit_euler(int, float*, float*, float, int);
