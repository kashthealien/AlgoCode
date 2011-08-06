mySum = 1
change = 2
curr = 1
for i in range(1,501):
	for j in range(4):
		curr += change
		mySum += curr
	change += 2
print mySum
