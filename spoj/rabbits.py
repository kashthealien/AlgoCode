def pow(x):
	y = 1
	for i in range(x):
		y *= 2
	return y

def fib(y):
	a = 0
	b = 1
	c = 0
	for i in range(y):
		c = a + b
		a = b
		b = c
	return c

for i in range(input()):
	n, m = map(int, raw_input().split())
	x = fib(n)
	y = pow(m)
	while y <= x: x -= y
	print x
	
