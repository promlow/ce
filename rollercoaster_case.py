import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    s = ''
    func = 'upper'
    for c in test:
        if c.isalpha():
            s += getattr(c, func)  
            if func == 'upper':
                func = 'lower'
            else:
                func = 'upper'
        else:
            s += c
    print s

test_cases.close()
