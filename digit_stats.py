import sys

nums = {'2': [2, 4, 8, 6],
        '3': [3, 9, 7, 1],
        '4': [4, 6],
        '5': [5],
        '6': [6],
        '7': [7, 9, 3, 1],
        '8': [8, 4, 2, 6],
        '9': [9, 1]}


test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    test.strip()
    if test:
        out = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        b, x = test.split()
        exp = long(x)
        last_digits = nums.get(b)
        m = exp // len(last_digits)
        for d in last_digits:
            out[d] = m
        rem = exp % len(last_digits)
        for r in range(rem):
            out[last_digits[r]] += 1

        print "0: %d, 1: %d, 2: %d, 3: %d, 4: %d, 5: %d, 6: %d, 7: %d, 8: %d, 9: %d" % tuple(out)
                
test_cases.close()

