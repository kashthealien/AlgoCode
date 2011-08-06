done = 0
while not done:
	x = input()
	if x == 0.0:
		done = 1
		continue
	y = 0.0
	n = 2
	while y < x:
		y += 1.0/n
		n += 1
	print n-2, "card(s)"
	
