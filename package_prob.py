import sys
import ast
from compiler.ast import flatten

W=1
C=2
I=0

def knapsack(weight, items):
    added = []
    mw = (-1, sys.maxint, -sys.maxint - 1)
    for item in items:
        if item[W] < weight:
            if item[C] >= mw[C] and item[W] < mw[W]:
                mw = item
            if item[C] > mw[C]:
                mw = item
            elif item[W] > mw[W]:
                mw = item

    if mw[I] > -1:
        added.append(mw[I])
        items.remove(mw)
        added.append(knapsack(weight - mw[W], items))
    else:
        return added

    return flatten(added)

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    test.rstrip()
    if test:
        max_weight_str, tuple_str = test.split(':')
        max_weight = int(max_weight_str)
        items = []
        for t in tuple_str.split():
            items.append(ast.literal_eval(t.replace('$', '')))

        result = knapsack(max_weight, items)
        if len(result) == 0:
            print '-'
        else:
            print ",".join(map(str, sorted(result)))
                
test_cases.close()

