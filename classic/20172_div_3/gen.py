#!/usr/bin/python

import sys
for i in range(1, int(sys.argv[1])):
    print i, int(2**i/3+1)%1000000007
