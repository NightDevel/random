#!/usr/bin/python
import random as r

for a,b in [(r.randint(1,1000000000000000),r.randint(1,10000000000000000)) for i in range(1000)]:
    print a, b
