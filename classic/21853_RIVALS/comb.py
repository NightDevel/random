#!/usr/bin/python
import sys
import operator as op
def ncr(n, r):
    r = min(r, n-r)
    if r == 0: return 1
    numer = reduce(op.mul, xrange(n, n-r, -1))
    denom = reduce(op.mul, xrange(1, r+1))
    return numer/denom

a=int(sys.argv[1])
b=int(sys.argv[2])
c = ncr((a+b), a)
print c
print c % 1000000007
