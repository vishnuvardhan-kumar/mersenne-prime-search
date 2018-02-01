"""
A bunch of useful functions related to primality and prime generation.
"""

prime_list = [2, 3, 5, 7, 11, 13, 17, 19, 23]   
prime_dict = dict.fromkeys(prime_list, 1)
lastn      = prime_list[-1]

def _isprime(n):
    ''' Raw check to see if n is prime. Assumes that prime_list is already populated '''
    isprime = n >= 2 and 1 or 0
    for prime in prime_list:                    
        if prime * prime > n: break             
        if not n % prime:
            isprime = 0
            break
    if isprime: prime_dict[n] = 1               
    return isprime

def _refresh(x):
     ''' Refreshes primes upto x '''
     global lastn
     while lastn <= x:                           
         lastn = lastn + 1                       
         if _isprime(lastn):
             prime_list.append(lastn)            

def prime(x):
    ''' Returns the xth prime '''
    global lastn
    while len(prime_list) <= x:                 
        lastn = lastn + 1                       
        if _isprime(lastn):
            prime_list.append(lastn)                 
    return prime_list[x]

def isprime(x):
     ''' Returns 1 if x is prime, 0 if not. Uses a pre-computed dictionary '''
     _refresh(x)                                 
     return prime_dict.get(x, 0)                 

def factors(n):
     ''' Returns a prime factors of n as a list '''
     _refresh(n)
     x, xp, f = 0, prime_list[0], []
     while xp <= n:
         if not n % xp:
             f.append(xp)
             n = n / xp
         else:
             x = x + 1
             xp = prime_list[x]
     return f

def all_factors(n):
    ''' Returns all factors of n, including 1 and n '''
    f = factors(n)
    elts = sorted(set(f))
    numelts = len(elts)
    def gen_inner(i):
        if i >= numelts:
            yield 1
            return
        thiselt = elts[i]
        thismax = f.count(thiselt)
        powers = [1]
        for j in xrange(thismax):
            powers.append(powers[-1] * thiselt)
        for d in gen_inner(i+1):
            for prime_power in powers:
                yield prime_power * d
    for d in gen_inner(0):
        yield d

def num_factors(n):
    ''' Returns the number of factors of n, including 1 and n '''
    div = 1
    x = 0
    while n > 1:
        c = 1
        while not n % prime(x):
            c = c + 1
            n = n / prime(x)
        x = x + 1
        div = div * c
    return div

"""
A python implementation of the Rabin-Miller algorithm.
"""

def is_prime_prob(n, k=10):
    if n == 2:
        return True
    if not n & 1:
        return False

    def check(a, s, d, n):
        x = pow(a, d, n)
        if x == 1:
            return True
        for i in range(s - 1):
            if x == n - 1:
                return True
            x = pow(x, 2, n)
        return x == n - 1

    s = 0
    d = n - 1

    while d % 2 == 0:
        d >>= 1
        s += 1

    for i in range(k):
        a = randrange(2, n - 1)
        if not check(a, s, d, n):
            return False
    return True

"""
A python implementation of the Sieve of Eratosthenes.
"""

def prime_sieve(limit):
    a = [True for _ in range(limit)]                         
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in xrange(i*i, limit, i):     
                a[n] = False

    return a

if __name__ == '__main__':
    sieved = prime_sieve(1000000)
    assert isinstance(sieved, list)
    print("Sieve successfully built and populated.")

