#!/usr/bin/python
import random as r
print 100
print r.randint(0,100)
a=[r.randint(-100000, 100000) for i in range(100)]
for i in a:
	print i

print "=========="
b=sorted(a)
print b
print sum(b)


