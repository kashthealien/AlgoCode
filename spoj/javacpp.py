import string
flag = 1
while flag:
	try:
		li = []
		mode = 0
		x = raw_input()
		y=""
		upper = 0
		for c in x:
			li.append(c)
			if c in string.ascii_uppercase:
				if mode==2:
					mode=3
				else:
					mode=1
			elif c=='_':
				if mode==1:
					mode=3
				else:
					mode=2
		if mode==3:
			print "Error!"
		elif mode==2:
			for c in x:
				if c == '_':
					upper = 1
					prin = 0
				else
					prin = 1
				if prin:
					if 
		print x
	except EOFError:
		flag = 0;
		
