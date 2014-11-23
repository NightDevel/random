#!/usr/bin/python
import sys
def found_sol(l, v):
    for i in l:
        if v%i == 0:
            return 1
    return 0

def get_total_jobs(l, v):
    return sum([v/i for i in l])

def get_time(n, j, values):
	max_t = j * min(values)
	low  = 0
	high = max_t
	mid  = (low+high)/2
	while True:
#		print low, mid, high
		tjobs = get_total_jobs(values, mid)
#		print tjobs
		if tjobs >= j:
			if get_total_jobs(values, mid-1) < j:
				break
		if tjobs < j:
			low = mid+1
		else:
			high = mid-1
		
		mid = (low+high)/2
	return mid

inp = sys.stdin.read().splitlines()
inp = filter(None, inp)
t = int(inp[0])
k = 1
for i in range(t):
	n, j = map(int, inp[k].strip().split())
	k += 1
	values = [0] * n
	for  i in range(n):
		values[i] = int(inp[k].strip())
		k += 1
	print get_time(n, j, values)
sys.exit(1)
