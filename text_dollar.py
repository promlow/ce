import sys

words = ['', 'one', 'two', 'three', 'four', 'five', 'six', 
         'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve',
         'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen',
         'eighteen', 'nineteen']


def convert(val):
    s = ''
    if val < 20:
        s = words[val].capitalize()
    elif val < 30:
        s = "Twenty" + convert(val % 20)
    elif val < 40:
        s = "Thirty" + convert(val % 30)
    elif val < 50:
        s = "Forty" + convert(val % 40)
    elif val < 60:
        s = "Fifty" + convert(val % 50)
    elif val < 70:
        s = "Sixty" + convert(val % 60)
    elif val < 80:
        s = "Seventy" + convert(val % 70)
    elif val < 90:
        s = "Eighty" + convert(val % 80)
    elif val < 100:
        s = "Ninety" + convert(val % 90)
    elif val >= 1000000:
        s = convert(val/1000000) + "Million" + convert(val % 1000000)
    elif val >= 1000:
        s = convert(val/1000) + "Thousand" + convert(val % 1000)
    elif val >= 100:
        s = convert(val/100) + "Hundred" + convert(val % 100)

    return s

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    test.strip()
    if test:
        val = int(test)
        print convert(val) + "Dollars"
                
test_cases.close()

