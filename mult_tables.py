
import sys

s = ""

for i in range(1, 13):
    for j in range(1, 13):
        s = s + '{:>4}'.format(str(i * j))
    s = s + '\n'
    
print s
            
            
