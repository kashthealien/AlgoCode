values = { "S" : 0, "." : 1, ".." : 2, "..." : 3, "...." : 4, "-" : 5, ". -" : 6, ".. -" : 7, "... -" : 8, ".... -" : 9,
		 "- -" :10, ". - -" :11, ".. - -" :12, "... - -" :13, ".... - -" :14, "- - -" :15, ". - - -" :16, ".. - - -" :17,
		 "... - - -" :18, ".... - - -" :19 }
x = 1
while x > 0:
	x = input()
	li = []
	for i in range(x):
		li.append(raw_input())
	if len(li) == 1:
		print values[li[0]]
	elif len(li) == 2:
		print values[li[1]] + values[li[0]] * 20
	elif len(li) == 3:
		print values[li[2]] + values[li[1]] * 20 + values[li[0]] * 360
	elif len(li) > 3:
		value = values[li[-1]] + values[li[-2]] * 20 + values[li[-3]] * 360
		li.pop(-1)
		li.pop(-1)
		li.pop(-1)				
		multi = 7200
		while len( li ) > 0:
			value = value + multi * values[li[-1]]
			li.pop(-1)
			multi = multi * 20
		print value
	if x > 0:
		raw_input()
