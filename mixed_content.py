import sys

file = open(sys.argv[1])

for line in file:
    line = line.strip()
    if line:
        words = []
        digits = []
        
        all = line.split(',')
        for s in all:
            try:
                digits.append( int(s) )
            except ValueError:
                words.append( s)


        out = ""
        if words:
            for word in words:
                out = out + word + ','
            if digits:
                out = out.rstrip(',') + '|'
                for num in digits:
                    out = out + str(num) + ','
            out = out.rstrip(',')
        elif digits:
            for num in digits:
                out = out + str(num) + ','
            out = out.rstrip(',')

        print out
            
