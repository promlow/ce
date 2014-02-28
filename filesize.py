import sys

f = open(sys.argv[1])
for l in f:
    floats = l.split()
    s = 0.0
    for fl in floats:
        s += float(fl)
            
            
    print s
