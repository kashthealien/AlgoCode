N = input()
while 1:
	try:
		check = 0;
		i = 0
		count = 0
		string2 = ""
		x = int(raw_input())
		N -= 1
		string =  '%.12f' % pow(x, 0.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333)
		for c in string:
			string2 += c
			if c == '.':
				count = 1
			elif ord(c) >= ord('0') and ord(c) <= ord('9'):
				check = check + (ord(c) - 48)
				if count:i += 1
			if i == 10: break
		print check % 10, string2
	except:continue
	if not N:break
