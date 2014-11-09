#!/usr/bin/python
import sys
def power_mod(a, p, m):
    c = 1
    while p > 1:
        if p%2 == 0:
            t = a * a
            if t >= m:
                t = t % m
            a = t
            p = p/2
        else:
            t = c * a
            if t >= m:
                t = t % m
            c = t
            p -= 1
    return (c * a) % m;

#using formula
#graph coloring for a cycle graph
#pow((k-1), n) + pow(-1, n) * (k-1)


mod = 1000000007
#this line saved my day
inp = sys.stdin.readlines()
T = int(inp[0].strip())
for i in range(1, T+1):
    N, K = map(int, inp[i].strip().split())
    #pow(a, p-1) % p = 1 % p, if p is prime
    #pow(k-1, n) % mod = (pow(k-1, (mod-1)*l) % mod * pow(k-1, n%(mod-1))%mod)%mod
    #                  =             1              * pow(k-1, n%(mod-1))%mod
    # pow(k-1, n)%mod = pow(k-1, n%(mod-1)) % mod

    # this one too
    n = int(N % (mod-1))
    k = int((K-1) % (mod))
    v = power_mod(k, n, mod)

    if N % 2 == 0:
        v = v + k
    else:
        v = v - k
        if v < 0:
            v += mod

    print v % mod
