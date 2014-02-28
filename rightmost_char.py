import sys

f = open(sys.argv[1])

for line in f:
    line = line.strip()
    if line:
        [s, t] = line.split(',')
        print s.rfind(t)
