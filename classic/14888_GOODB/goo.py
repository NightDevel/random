#!/usr/bin/python

def fact(n):
    p = 1
    for i in range(2, n+1):
        p = p * i
    return p

N, W, T, R = map(int, raw_input().split())

#print fact(N)
print (fact(N)/(fact(W)*fact(T)*fact(R)))%1000000007
