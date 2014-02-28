
import sys

file = open(sys.argv[1], 'r')

for line in file:
    if (len(line) > 2):
        words = line.split()
        words.reverse()
        s = ""
        for word in words:
            s = s + word + ' '

        print s.rstrip()

file.close()
            
            
