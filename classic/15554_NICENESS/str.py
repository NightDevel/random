#!/usr/bin/python
T=int(raw_input())
while T: 
    print len(set(w[::-1]  for w in raw_input().split()))
    T -= 1
