#!/usr/bin/python
import random
import sys
#l=[0.03, 0.02, 0.03, 0.2, 0.05, 0.06, 0.08, 0.2, 0.07, 0.09, 0.015, 0.016, 0.014, 0.025, 0.10]
l=[0.05, 0.0, 0.03, 0.2, 0.05, 0.06, 0.08, 0.2, 0.07, 0.09, 0.015, 0.016, 0.014, 0.025, 0.10]

e = int(sys.argv[1])
print e
for k in range(e):
    print 15
    for i in range(15):
        random.shuffle(l)
        for p in l:
            print p,
        print

