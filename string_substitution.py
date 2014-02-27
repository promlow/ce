#!/usr/bin/env python



#10011011001;0110,1001,1001,0,10,11

#10011011001 => 10100111001 [replacing 0110 with 1001] 
#10100111001 => 10100110 [replacing 1001 with 0] 
#10100110 => 11100110 [replacing 10 with 11]. 
#So the answer is 11100110 

import sys

if (len(sys.argv)) < 2:
    print "file name required"
    exit(-1)

file_name = sys.argv[1]

f = open(file_name)

def replace(s, f, r, i, y):
    sa = bytearray(s)
    fa = bytearray(f)
    ra = bytearray(r)

    if (len(f) > len(r)):
        #remove len(f) - len(r) from s
        sa[i:i+len(f)] = r
        y[i:i+len(f)] = ['1'] * len(r)

        for x in range(i+len(f), len(s) - 2):
            sa[x] = sa[x+1]

    elif (len(r) > len(f)):
        #insert len(r) - len(f) into s
        del sa[i:i+len(f)]
        del y[i:i+len(f)]
        j = i
        for c in r:
            sa.insert(j, c)
            y.insert(j, '1')
            j = j+1
    else:
        sa[i:i+len(f)] = r
        y[i:i+len(f)] = ['1'] * len(r)

    return str(sa)
    


for l in f:
    [s, tmp] = l.rstrip().split(';')
    fr = tmp.split(',')
    f = []
    for i in range(0, len(fr), 2):
        f.append(fr[i])

    r = []
    for i in range(1, len(fr), 2):
        r.append(fr[i])

    z = "0"
    y = bytearray(z.zfill(len(s)))

    for find in f:
        done = False
        j = 0
        while not done:
            i = s.find(find, j)
            if(i > -1):
                if '1' in y[i:i+len(find)]:
                    j = j+len(find)
                else:
                    find_idx = f.index(find)
                    repl = r[find_idx]
                    s = replace(s,find,repl,i, y)
                    done = True
                    j = 0

    print s
