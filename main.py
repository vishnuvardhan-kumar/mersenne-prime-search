from random import randrange
import time

def is_prime(n, k=10):
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


base = 2
exponent = 2000
starttime = time.time()
count = 0

try:
    while True:
        if is_prime(base**exponent-1):
            print(f"M({exponent}) is probably prime")
        exponent+=1
        count+=1
except KeyboardInterrupt:
    print("Found {} probable primes in {} seconds".format(count, time.time()-starttime))    
