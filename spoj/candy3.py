for i in range(input()):
	x = raw_input()
	x = input()
	y = 0
	for j in range(x):
		y += input()
	if y%x: print "NO"
	else:   print "YES"

