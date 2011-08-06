def fact(x): return (1 if x==0 else x * fact(x-1))
x, y = map(int, raw_input().split())
while x:
	print fact(y+x-1) / fact(x-1)
	x, y = map(int, raw_input().split())

