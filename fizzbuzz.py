
import sys

file = open(sys.argv[1], 'r')

for line in file:
    if (len(line) > 2):
        [f, b, l] = line.split()
        fizz = int(f)
        buzz = int(b)
        limit = int(l)
        
        s = ''
        for i in range(1, limit + 1):
            if (i % fizz > 0 and i % buzz > 0):
                s = s + str(i)
            if (i % fizz == 0):
                s = s + 'F'
            if (i % buzz == 0):
                s = s + 'B'
            if (i < limit):
                s = s + ' '

        print s

file.close()
            
            
