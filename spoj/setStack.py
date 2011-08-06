def remDup(seq): 
    checked = []
    for e in seq:
        if e not in checked:
            checked.append(e)
    return checked

def sub(list1, list2):
	for i in range(len(list2)):
		list1.remove(list2[i])


for i in range(input()):
	x = []
	for j in range(input()):
		y = raw_input()
		if y == "PUSH": x.append([])

		elif y == "DUP": 
			z = x.pop(-1)
			x.append(z)
			x.append(z)

		elif y == "UNION":
			z = x.pop(-1)
			w = x.pop(-1)
			x.append(remDup(z+w))

		elif y == "INTERSECT":
			z = x.pop(-1)
			w = x.pop(-1)
			x.append(sub(z+w,remDup(z+w)))

		elif y == "ADD":
			z = x.pop(-1)
			w = x.pop(-1)
			print z, w
			w.insert(-1,z)
			print w
			x.append(w)
		
		print y
		print x
		print len(x[-1])
	print "***"
