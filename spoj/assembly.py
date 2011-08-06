D=C=0
for c in raw_input():
	if c.isupper():
		while C%4:
			C+=1
			D+=1
	C+=1
print D
