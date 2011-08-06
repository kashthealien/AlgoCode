def subst(s,m): return s
for i in range(input()):
	a=raw_input()
	l=[]
	m={}
	n={}
	N=input()
	for n in range(N): l.append(subst(raw_input(),m))
	l.sort()
	for n in range(N): l[n] = subst(l[n],n)
	try:raw_input()
	except:break
	for n in range(N): print(l[n])
	print
