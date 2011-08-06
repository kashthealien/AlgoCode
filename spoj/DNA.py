for i in range(input()):
	for j in range(input()):
		x=raw_input()
		y=[]
		if(x.find('A') and x.find('T') and x.find('G') and x.find('C')):
			y.append(x)
	print min(y)
