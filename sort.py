import sys
from decimal import *

f = open(sys.argv[1])
getcontext().prec = 10
for l in f:
    floats = map(Decimal, l.split())
    floats.sort()
    s = ""
    for fl in floats:
        s = s + str(fl) + ' '
            
            
    print s.rstrip()
