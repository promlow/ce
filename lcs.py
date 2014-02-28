import sys

def lcs_arr(a, b):
    m = max(len(a) + 1, len(b) + 1)
    L = [[0 for x in xrange(m)] for x in xrange(m)]
    amax = len(a)
    bmax = len(b)
    for i in range(amax, -1, -1):
        for j in range(bmax, -1, -1):
            if i == amax or j == bmax: continue
            elif a[i] == b[j]: L[i][j] = 1 + L[i+1][j+1]
            else: L[i][j] = max(L[i+1][j], L[i][j+1])
            
    return L

def lcs(a, b):
    L = lcs_arr(a, b)
    s = ""
    i = 0
    j = 0
    m = len(a)
    n = len(b)
    while i < m and j < n:
        if a[i] == b[j]:
            s = s + a[i]
            i = i + 1
            j = j + 1
        elif (L[i+1][j] >= L[i][j+1]): i = i + 1
        else: j = j + 1

    return s

f = open(sys.argv[1])
for l in f:
    l = l.strip()
    if l:
        [a, b] = l.split(';')
        s = lcs(a, b)
        print s
