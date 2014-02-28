import sys
import math

f = open(sys.argv[1])

def one_if_prime(n):
    if n == 1: return 0
    if n == 2: return 1
    
    i = 2
    sqrt = math.ceil(math.sqrt(n))
    while i <= sqrt:
        if n % i == 0:
            return 0
        else:
            i = i + 1
            
    return 1        

for l in f:
    l = l.strip()
    if l:
        [m, n] = l.split(',')
        i = 0
        for j in range(int(m), int(n)):
            i = i + one_if_prime(j)

        print i
