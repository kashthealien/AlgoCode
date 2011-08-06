for x in range(input()):
	y=input()
	print(y*(y+1)*(y+2)/6)+((y%2==0)and(y*(2*y*y+3*y-2)/24)or((y-1)*(2*y*y+5*y+3)/24))
	
"""(l-1)(2LL + 5 +3)/24
(L)(L+1)(L+2)/6
(L)(2LL + 3L - 2)/24"""
