import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if (not test.rstrip()): continue
    else: print test.title().strip('\n')
