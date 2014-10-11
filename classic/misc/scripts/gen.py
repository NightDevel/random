#!/usr/bin/python
import random as r
print 100000
for i in range(100000):
    a,b=[r.randint(-2147483648, 2147483648-1) for i in range(2)]
    if a > b:
        a,b=b,a
    print a, b
    


