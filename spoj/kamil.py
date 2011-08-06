for i in range(10):
	x=raw_input()
	print 2**len([c for c in x if c in "TDLF"])
