for i in range(input()):
	N, I, M = map(int, raw_input().split())
	
	# Get the original permutation
	li = []
	li2 = []
	for n in range(N):
		li.append(n+1)
		li2.append(0)
	
	# Decide what elements to move and by how much
	while(I):
		t = 1
		P = 1
		while(P*t <=I):
			P *= t
			t += 1
		Q = I/P
		li2[t-1] = Q
		I -= Q*P
	# Get the I'th permutation
	for n in range(N-1,0,-1):
		pos = N - n - 1
		x = li.pop(pos+li2[n])
		li.insert(pos, x)

	# Get and print the next m permutation
	for m in range(M):
	 	for i in li: print i,						# Print the list
	 	print
		#Get next permutation of 'li'
		flag = 1
		for i in range(N-1):
			if li[i] < li[i+1]: flag = 0

		if flag:
			li = []
			for i in range(1, N+1):
				li.append(i)
		else:
			i = N-1
			while(li[i] < li[i-1]): i -= 1
			i -= 1
			x = li[i]
		
			j = N-1
			while(li[j] < x): j -= 1
			y = li[j]
			li[i] = y
			li[j] = x
		
			li3 = []
			for k in range(i+1,N):
				li3.append(li[k])
			li3.sort()
			for k in range(i+1,N):
				li[k] = li3[k-i-1]
	print
		
