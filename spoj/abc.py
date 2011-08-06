def gcd(x, y): return( x if y == 0 else gcd(y, x%y))
i = 1
while i:
	x, y, z = map(int, raw_input().split())
	if ( x == 0 and y == 0 ): i = 0
	else
		if x >= y: a = gcd(x, y)
		else: a = gcd(y, x)
		if z % a  == 0:
			print "YES"
		else:
			print "NO"
	
	
	
