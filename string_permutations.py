import sys

def perm(pre, s):
    #print pre, s
    l = []
    if(len(s) == 0): 
        return [pre]
    else:
        for i in range(0,len(s)):
            prefix = pre + s[i]
            l.extend(perm(prefix, s[:i]+s[i+1:]))

    return l

f = open(sys.argv[1])
for l in f:
    l = l.strip()
    if l:
        perms = perm("", l)
        perms.sort()

        s = ""
        for p in perms:
            s = s + p + ','

        print s.rstrip(',')
