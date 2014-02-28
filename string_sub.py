import sys

def replace(s, f, r, i, y):
    sa = bytearray(s)
    fa = bytearray(f)
    ra = bytearray(r)

    if (len(f) > len(r)):
        #remove len(f) - len(r) from s
        sa[i:i+len(f)] = r
        y[i:i+len(f)] = ['1'] * len(r)

        for x in range(i+len(f), len(sa) - 2):
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

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if (len(test) < 2): continue
    [s, tmp] = test.rstrip().split(';')
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
            else:
                done = True

    print s

    
test_cases.close()
