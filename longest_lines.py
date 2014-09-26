import sys
import heapq

test_cases = open(sys.argv[1], 'r')
first = True
for test in test_cases:
    test = test.rstrip()
    if test:
        if first:
            h = [(-1 * n, '') for n in range(int(test))]
            heapq.heapify(h)
            first = False
        else:
            heapq.heappushpop(h, (len(test), test))

test_cases.close()
result = []
for i in xrange(len(h)):    
    result.append(heapq.heappop(h)[1])

for s in reversed(result):
    print s
    

