import sys

f = open(sys.argv[1])

for l in f:
    l = l.strip();
    if l:
        [s1, s2] = l.split(';')
        nums1 = s1.split(',')
        nums2 = s2.split(',')

        set1 = set(nums1)
        set2 = set(nums2)

        intset = set1.intersection(set2)
        sl = []
        for n in intset:
            sl.append(n)

        sl.sort()

        s = ""

        for i in sl:
            s += i + ',';

        print s.rstrip(',')
