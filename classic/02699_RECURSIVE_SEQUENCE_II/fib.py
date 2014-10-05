#!/usr/bin/python

import sys
a=int(sys.argv[1])
b=int(sys.argv[2])

def fib(n):
    if n == 1 or n == 2:
        return 1
    return fib(n-1)+fib(n-2)

sum=[0]*(b+1)
sum[0] = 0
for i in range(1, b+1):
    sum[i] = sum[i-1] + fib(i)

print sum[b]-sum[b-1]
print sum[a]-sum[a-1]
print sum[b]-sum[a-1]
