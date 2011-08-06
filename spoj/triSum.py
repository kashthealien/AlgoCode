for i in range(input()):
	x=[]
	for j in range(input()):x+=[raw_input().split()]
	z=x.pop(-1)
	while len(x):
		y=x.pop(-1)
		for k in range(len(y)):y[k]=int(y[k])+int(max(z[k],z[k+1]))
		z=y
	print z[0]

		
