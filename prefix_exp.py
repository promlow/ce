import sys
from collections import deque

f = open(sys.argv[1])

def parse(tokens):
    token=tokens.popleft()
    if token=='+':
            return parse(tokens)+parse(tokens)
    elif token=='-':
            return parse(tokens)-parse(tokens)
    elif token=='*':
            return parse(tokens)*parse(tokens)
    elif token=='/':
            return parse(tokens)/parse(tokens)
    else:
            # must be just a number
            return int(token)


for l in f:
    l = l.strip()
    if l:
        stack = []
        exp = l.split()
        deq = deque(exp)
        print parse(deq)
