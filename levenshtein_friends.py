#!/usr/bin/env python

import sys

def levenshtein(s, t):

    if (s == t):      return 0;
    if (len(s) == 0): return len(t)
    if (len(t) == 0): return len(s)

    # create two work vectors of int distances
    

if (len(sys.argv)) < 2:
    print "file name required"
    exit(-1)

file_name = sys.argv[1]

print file_name



