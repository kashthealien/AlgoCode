def unConvert(num, base):
	answer =''
	stack =[]
	while num != 0:
		x = num % base;
		num /= base;
		if x<=9: stack.append(x+48)
		else: stack.append(x+55)
	while(len(stack)): answer += chr(stack.pop())
	return answer

def convert(st, base):
	result = 0
	power = 1
	length = len(st);
	i = length - 1
	while i>=0:
		if ord(st[i]) <= 57: temp = ord(st[i])-48
		else: temp = ord(st[i])-55
		result += temp * power
		power *= base
		i -= 1
	return result;

for i in range(input()):
	x=raw_input()
	y=raw_input()
	a=convert(x, 36)
	b=convert(y, 36)
	c=a+b
	z=unConvert(c, 36)
	print z
