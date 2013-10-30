na-euler-methods
================

This is source code is for the course [MAT 3633 -- Numerical Analysis](http://zeta.math.utsa.edu/~zjo970/teaching/2012tfall/12f_numanal/12f_numanal_home.html) offered at the University of Texas at San Antonio.

While quite a bit of the code is more exhaustive than I planned to share, this will help you move along in the course. Most of my effort has gone to streamlining output since the equations are easy
to implement.

This code specifically aims to implement explicit and implicit Euler discrete approximations. The results/output may not be "perfect" (i.e., you won't always get what you expect), but I will use the old cliche in Math books and leave that as an exercise to the reader/student.


Installation
============

Simply run:

`	make -s`

And you should be ready to go.

Using
=====

The binary executable for this file is euler, so simply run

`	./numerical-euler`

and follow the prompts. To check to output, open euler.log to see how effectively you've approximated each DE. 


Notes
=====

I haven't been able to fix Problem #4. I took this class in Fall 2012, and abandoned it since then, so I don't remember everything
about the assignment (and I doubt the link above even has the forward/backward Euler assignments now). I've renewed my interest
in part due to [this blog post](http://thelimberlambda.com/2010/02/09/what-is-a-senior-developer/), so I may revisit this and
some other numerical methods in C. I don't expect people to actually *use* this, especially with the class long being over,
but at the time, we had leeway on how to program these methods, and a significant minority in the class didn't want to use MATLAB,
so I offered to help for those classmates wanting to use C (or Java). It must have turned out well, since we all graduated.
