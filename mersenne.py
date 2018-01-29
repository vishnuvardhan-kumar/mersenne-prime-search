from random import randrange
from prime import is_prime_prob
import time

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
