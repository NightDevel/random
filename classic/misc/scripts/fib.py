#!/usr/bin/python


n = int(raw_input())
n1 = 0
n2 = 1
print n1
print n2
while n:
	n3 = n2 + n1
	n2, n1 = n3, n2
	n -= 1
	print n3

