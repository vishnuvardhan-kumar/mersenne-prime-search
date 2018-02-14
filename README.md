# Mersenne Prime Search

My attempt to generate and verify arbitrarily large Mersenne primes.

<h4> Current largest: </h4>

> M(86243) == 2^86243 - 1 with 25962 digits (Pure Python3)

<h4> Mersenne primes: </h4>

From Wikipedia, the free encyclopedia

> Largest known term 	2^77,232,917 − 1 (December 2017)
> 
> OEIS index 	A000668

> In mathematics, a Mersenne prime is a prime number that is one less than a power of two. That is, it is a prime number of the form Mn = 2n − 1 for some integer n. They are named after Marin Mersenne, a French Minim friar, who studied them in the early 17th century.


<h4> The Algorithms: </h4>

> [Miller–Rabin primality test](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)

> [Lucas–Lehmer primality test](https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test)

<h4> How to Run </h4>

+ `git clone https://github.com/vishnuvardhan-kumar/mersenne-prime-search.git`

+  `cd mersenne-prime-search`
 
+  `python mersenne.py`

<h4> Project Roadmap </h4>

+ Move from Python3 to C/C++ (using a library such as GMP)
+ Parellize operations on threads/microthreads
+ Implement prime exponent paradigm

