for i in range(input()):
	y=input()
	if y%2==1:z=(y-1)/2
	else: z=y/2
	if y%2==1:x=z*(z+1)*(4*z+5)/6
	else:x=z*(z+1)*(4*z-1)/6
	print x
	print y*y*y
	x+=y*y*y
	print y*(y+1)*(4*y+2)/6
	x+=y*(y+1)*(4*y+2)/6;
	print 2*x

