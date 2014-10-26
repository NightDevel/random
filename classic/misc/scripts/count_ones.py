#!/usr/bin/python
import sys
def count_ones(n):
    c = 0
    for i in range(n+1):
        p = i
        while p:
            if p & 0x1:
                c += 1
            p = p >> 1;
    return c;

print count_ones(int(sys.argv[1]))
