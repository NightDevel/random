#!/usr/bin/python
import itertools
N = int(raw_input())
for n in range(1, N+1):
	for i in (itertools.product(['Y','N'], repeat=n)):
		print "".join(i)

