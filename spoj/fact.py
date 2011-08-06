def fact(x): return (1 if x==0 else x * fact(x-1))
Q = input()
for i in xrange(Q):
	x = input()
	print fact(x);
