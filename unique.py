import sys

f = open(sys.argv[1])

for l in f:
    l = l.strip();
    if l:
        nums = l.split(',')
        sl = []
        for n in nums:
            if n not in sl:
                sl.append(n)

        s = ""

        for i in sl:
            s += i + ',';

        print s.rstrip(',')
