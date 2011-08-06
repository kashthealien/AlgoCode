def posBaseConvert( num, base):
	que = []
	sign = 1

	if num < 0:
		sign = -1
		num = - num
	while num != 0:
		x = num % base
		num /= base
		que .append(x)
		
	if (sign>0):
		que.append('+')
	else:
		que.append('-')
	que.reverse()
	return que

def negBaseConvert( posBase, base):
	if posBase[0] == '+':
		par = 1
	else:
		par = 0
	answer = posBase
	answer.insert(0,0)
	answer[1] = 0;
	lent = len(answer)
	
	i = lent - 1
	j = 0
	while i >= 1:
		if j % 2 == par:
			if answer[i] != 0:
				answer[i] = base - answer[i];
				answer[i-1] += 1
		else:
			if answer[i] == base:
				answer[i] = 0
				answer[i-1] += 1
		i -= 1
		j += 1
	return answer;

def printDigits(num):
	lent = len(num)
	i = 0
	while(not num[i]):
		i += 1
	
	if lent - i > 100:
		print "No"
		return

	for i in range(0,lent):
		if num[i]:
			print lent - i - 1,
	print

for i in range(input()):
	num = input()
	value = posBaseConvert(num, 2)
	value = negBaseConvert(value, 2)
	printDigits(value)
	value = posBaseConvert(-num, 2)
	value = negBaseConvert(value, 2)
	printDigits(value)

