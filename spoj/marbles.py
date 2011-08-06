def fact(x): return (1 if x==0 else x * fact(x-1))
def C(x,y): return (fact(x)/fact(x-y)/fact(y))
for i in range(input()):
	x, y = map(int, raw_input().split())
	print C(x-1,y-1)
