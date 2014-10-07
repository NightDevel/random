#!/usr/bin/python


def pow_mod(a, p, m):
    if p == 1:
        return a%m

    if p == 0:
        return 1

    if p%2 == 0:
        return pow_mod((a*a)%m, p/2, m)%m
    else:
        return (a*pow_mod(a, p-1, m))%m



import sys
a = int(sys.argv[1])
p = int(sys.argv[2])
m = int(sys.argv[3])
print a, p, m
c = pow_mod(a, p, m)
print "ans", c

