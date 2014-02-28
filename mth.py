import sys

f = open(sys.argv[1])

for l in f:
    l = l.strip()
    if l:
        data = l.split()
        i = int(data.pop())
        if(len(data) >= i):
            print(data[-i])
