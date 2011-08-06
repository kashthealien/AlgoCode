def ncr(n,r): return(fact(n)/fact(r)/fact(n-r))
def fact(x): return (1 if x==0 else x * fact(x-1))
Q = input()
for i in xrange(Q):
	x = input()
	y = input()
	print ncr(x,y)
