import sys
from operator import itemgetter

f = open(sys.argv[1])

for line in f:
    line = line.strip()
    chars = {}
    if line:
        ll = line.lower()
        for c in ll:
            if not c in chars and c.isalpha() and not c.isspace():
                chars[c] = ll.count(c)

        tuplist = chars.items()
        tuplist = sorted(tuplist, key=itemgetter(1), reverse=True)
        beauty = 0
        v = 26
        for item in tuplist:
            beauty = beauty + item[1] * v
            v = v - 1

        print beauty
