import sys
from operator import itemgetter

f = open(sys.argv[1])

for line in f:
    line = line.strip()
    if line:
        [s, suf] = line.split(',')
        if s.endswith(suf):
            print 1
        else:
            print 0
