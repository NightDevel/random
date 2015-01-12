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
	return (b, a % b)

def power_mod(a, p, m):
	c = 1
	while p:
		if p & 1: 
			c = (c * a) % m
		a = (a * a) % m
		p = p >> 1

	return c 


mark=[True]*(10**6+1)

def gen_primes(n):
	mark[1] = False
	e = int(math.sqrt(n)) + 1
	for i in range(2, e):
		if mark[i]:
			p = 2*i
			while p < n:
				mark[p] = False
				p += i

def miller_rabin(n):
	if n < 2:
		return False

	if n == 2:
		return True

	if n % 2 == 0:
		return False

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
				return False

			if x == n-1:
				break

		if x != n-1:
			return False

	return True



def is_prime(n):
	if n < 10**6:
		return mark[n]

	if n % 2 == 0:
		return False

	if power_mod(2, n-1, n) == 1:  
		return miller_rabin(int(n));

	return False

def power(a, p):
	c = 1
	while p:
		if p & 1:
			c = c * a
		a = a * a
		p = p >> 1
	return c

def odd_prime_power(n):
	if n % 2 == 0:
		return False

	#now check whether n = p^k for some odd prime and k >= 1 
	# 1. is n a prime
	if is_prime(n):
		return True

	max_p = int(math.log(n, 2))
	for p in range(max_p, 1, -1):
		v = math.pow(n, 1.0/p)
		l = math.floor(v)
		h = math.ceil(v)
#        print("checking for ", n, p, l, h)
		if l**p == n and is_prime(int(l)):
			return True
		if l != h and h**p == n and is_prime(int(h)):
			return True

	return False 



gen_primes(10**6)
t = int(input())
while t:
	t -= 1
	n = int(input())
	if n == 1:
		print(0)
	elif n == 2:
		print(1)
	elif n == 4:
		print(n-1)
	else:
		p = n
		if p % 2 == 0:
			p = p//2
		if odd_prime_power(int(p)):
			print(n-1)
		else:
			print(1)



#    if (is_prime(n)):
#        print(n, "is a prime")
#    else:
#        print(n, "is not a prime")
#k = 0
#for i in range(int(input())):
#    if is_prime(i):
#        print(i, "is prime")
#        k+=1
#print(k)

