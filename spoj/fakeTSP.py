import re
from math import sqrt
#(?:[eE][+-]?\d+)?
s = raw_input()
C= re.findall(r"[+-]? *(?:\d+(?\.\d*)?|\.\d+)", s)
x = C[0], y = C[1]
print C
d = 0
while(1):
	s = raw_input()
	C= re.findall(r"[+-]? *(?:\d+(?:\.\d*)?|\.\d+)", s)
	if(len(C)==0): break
	print C[0], C[1]
	d = d + sqrt((float(x)-float(C[0]))*(float(x)-float(C[0])) + (float(y)-float(C[1]))*(float(y)-float(C[1])))
	x = C[0], y = C[1]
	print "The salesman has traveled a total of %.3f kilometers." %d

