#!/usr/bin/python

#prb nr1
MAX_N = 32
s=[[0]*MAX_N for i in range(MAX_N)]
def generate_stirling(N):
    
    for i in range(N+1):
        s[i][0] = 0
        s[0][i] = 0
    s[0][0] = 1

    p = 1
    for n in range(1, N+1):
        #print n, ":",
        for k in range(1, n+1):
            s[n][k] = s[n-1][k-1] - (n-1) * s[n-1][k]
            #print p, " ", s[n][k]," "
            p += 1
        #print

def generate_data(l, m):
    l1 = l.pop()
    m1 = m.pop()
    a = [m1*i for i in s[l1]]
    while len(l) > 0:
        l1 = l.pop()
        m1 = m.pop()
        b = [m1*i for i in s[l1]]
        print a, b
        c = [sum(i) for i in zip(a,b)]
        a = list(c)
    print a[::-1]


generate_stirling(27);
#generate_data([10,20,25], [7,11,13])

#lets find out A1, A2, A3 ... An now
t = int(raw_input())
#t = 0
for v in range(t):
    inp=""
    while not inp:
        inp = raw_input().rstrip()
        if inp:
            n, k = map(int, inp.split())
    inp=""
    while not inp:
        inp = raw_input().rstrip()
        if inp:
            B  = map(int, inp.split()[::-1])
    #print n, k
    #print B


    A=[0] * (n+1)
    #print "==========="
    for i in range(n, 0, -1):
        t = 0
        j = n
        for j in range(n, i, -1):
            l = s[j][i] * A[j]
            t += l
            #print "partial", i, j, s[j][i], A[j], l
        A[i] = (B[i] - t)/s[i][i]
        #print i, t, B[i], s[i][i]
        #print "res =", A[i]
    A[0] = B[0]
    #print A
    C = list(A)        
    #forward differentiation
    #print C
    l = n;
    for i in range(k):
        for i in range(1, l+1):
            C[i-1] = C[i] * i;
        C[l] = 0
        l -= 1
    #print C
    print C[0]
