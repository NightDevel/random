#!/usr/bin/python
import math
import sys
arr = [
		[2047,                1, 2],
		[1373653,             2, 2, 3],
		[9080191,             2, 31, 73],
		[25326001,            3, 2, 3, 5],
		[4759123141,          3, 2, 7, 61],
		[1122004669633,       4, 2, 13, 23, 1662803],
		[2152302898747,       4, 2, 3, 5, 7, 11],
		[3474749660383,       6, 2, 3, 5, 7, 11, 13],
		[341550071728321,     7, 2, 3, 5, 7, 11, 13, 17],
		[3825123056546413051, 9, 2, 3, 5, 7, 11, 13, 17, 19, 23],
		]

def get_array(n):
	for i in range(10):
		if n < arr[i][0]:
			return i



def gcd(a, b):
	if not b:
		return a
	return gcd(b, a % b)

def power_mod(a, p, m):
	c = 1
	while p:
		if p & 1: 
			c = (c * a) % m
		a = (a * a) % m
		p = p >> 1

	return c


def miller_rabin(n):
	if n < 2:
		return False, 1

	if n == 2:
		return True, 0

	if n % 2 == 0:
		return False, 2

	d = n - 1
	s = 0
	while d % 2 == 0:
		s += 1
		d = d//2

	p = arr[get_array(n)];
	l = p[1];
	for i in range(l):
		a = p[i+2];
		x = power_mod(a, d, n);
		if x == 1 or  x == (n-1):
			continue

		for j in range(s):
			x = (x * x) % n;
			if x == 1:
				return False, a

			if x == n-1:
				break

		if x != n-1:
			return False, a

	return True, 0



def odd_prime_power(n):

	if n % 2 == 0:
		return False

	q = n
	while True:
		r, a = miller_rabin(q)
		if r:
			break

		d = gcd(power_mod(a, q, n) - a, q)
		if d == 1 or d == q:
			return False
		q = d

	while n % q == 0:
		n = n / q

	if n == 1:
		return True

	return False




#gen_primes(10**6)
t = int(input())
while t:
	t -= 1
	n = int(input())
#	print(n)
	if n == 1:
		print(0)
	elif n == 2:
		print(1)
	elif n == 4:
		print(n-1)
	else:
		p = n
		if p % 2 == 0:
			p = n//2

		if odd_prime_power(int(p)):
			print(n-1)
		else:
			print(1)

