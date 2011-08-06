import re

for i in range(int(raw_input())):
	inp = raw_input()
	is_num =  re.compile('[0-9]+')
	while not is_num.match(inp): inp = raw_input()
	x=int(inp)
	if x%5==0 or x%10 == 0:
		print -1
		continue
	done = 0									# Not yet done
	for j in range(1,201):						# Generate only upto 200 strings
		k=j
		for k in range(j,-1,-1):					# get a string with j-k 8s and k 6 s
			z=""								# Initially empty string
			for l in range(j-k): z += '8'		# Add the 8s
			for l in range( k ): z += '6'		# Add the 6s
			y = int(z)							# get the integer form of the string
			if y % x == 0:						# Check if its an answer
				print y							# print it
				done = 1						# We are done
			if done: break
		if done: break
	if not done: print -1
