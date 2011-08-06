I=[]
b=0
l=[]
r=[]
n=0
c = 1
for i in range(input()):
	I.append((input(),c))
	n = n + I[-1][0]
	c += 1
n /= 2
I.sort()
while(b<n):	
	l.append(I.pop())
	b += l[-1][0]
if (abs(n-b)>abs(n-b-I[-1][0])):
	l.append(I.pop())
	
while(len(l)):
	print l.pop()[1]
