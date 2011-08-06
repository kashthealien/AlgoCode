from math import sqrt
for i in range(1,500):
	for j in range (1,i):
		x = i*i - j*j
		y = int(sqrt(x))
		if y*y + j*j == i*i:
			if y + i + j == 1000:
				print i,j,y
