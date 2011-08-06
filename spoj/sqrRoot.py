import math

for i in range(input()):
	try:
		x = raw_input()
		j = int(x)
		print int(math.sqrt(j))
	except:
		i -= 1
		continue
