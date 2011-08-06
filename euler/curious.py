for i in range(10,100):
	for j in range(10,i):
		if j % 10 == 0 or i % 10 == 0:
			continue
		if float(j)/float(i) == float(int(j/10))/float(int(i/10)) and j%10 == i%10:
			print j,i
		if float(j)/float(i) == float(int(j/10))/float(int(i%10)) and j%10 == i/10:
			print j,i
		if float(j)/float(i) == float(int(j%10))/float(int(i/10)) and j/10 == i%10:
			print j,i
		if float(j)/float(i) == float(int(j%10))/float(int(i%10)) and j%10 == i%10:
			print j,i
		
