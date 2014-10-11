#!/usr/bin/python
import sys
def gcd(a, b):
    while True:
        if a == b:
            return a
        if b > a:
            a,b=b,a
        a = a-b

def lcm(a, b):
    return (a*(b/gcd(a,b)))

l = 1
for i in range(2, 21):
    l = lcm(l, i)
    print i, l
    raw_input()
