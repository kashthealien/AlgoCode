import sets
for i in range(input()):
	x=[]
	for j in range(input()):
		str = raw_input()
		if str == "PUSH": x.append(sets.Set([]))
		elif str == "DUP": x.append( x[-1])
		elif str == "UNION":
			a = x.pop(-1)
			b = x.pop(-1)
			x.append(a.union(b))
		elif str == "INTERSECT":
			a = x.pop(-1)
			b = x.pop(-1)
			x.append(a.intersection(b))
		elif str == "ADD":
			a = x.pop(-1)
			b = x.pop(-1)
			a.add(b)
			x.append(a)
		print len(x[-1])
	print "***"
