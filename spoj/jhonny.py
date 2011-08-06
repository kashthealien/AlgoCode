I=[]
b=0
l=[]
r=[]
n=1
for i in range(input()):
	I.append((input(),n))
	n += 1
I.sort()
while(len(I)):	
	if(b>=0):
		l.append(I.pop())
		b -= l[-1][0]
	else:
		r.append(I.pop())
		b += r[-1][0]
while(len(l)):
	print l.pop()[1]
