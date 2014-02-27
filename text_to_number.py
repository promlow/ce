import sys

f = open(sys.argv[1])

def convert(word):
    return {
        'negative': '-',
        'zero' : '0',
        'one'  : '1',
        'two'  : '2',
        'three': '3',
        'four' : '4',
        'five' : '5',
        'six'  : '6', 
        'seven': '7',
        'eight': '8',
        'nine' : '9',
        'ten'  : '10',
        

for line in f:
    line = line.strip()
    if line:
        
