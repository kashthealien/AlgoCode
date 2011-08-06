def gcd(x, y): return( x if y == 0 else gcd(y, x%y))
for i in range(input()):
	x, y = map(int, raw_input().split())
	print gcd(x, y)

