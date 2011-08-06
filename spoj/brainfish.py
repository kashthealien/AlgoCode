s=""
o=""
e="COMPILE ERROR"
M=32768
f=p=q=0
l=[]
t=[]
for i in range(M):l.append(0)
while f==0:
	try:s+=(raw_input().split('%'))[0]
	except EOFError:f=1
for c in s:
	if c=='[':f=f+1
	if c==']':f=f-1
	if f<1:print e
if f!=1:print e
while p<len(s)and f==1:
	h=s[p]
	if h=='+':l[q]=l[q]+1
	if h=='-':l[q]=l[q]-1
	if h=='>':q=q+1
	if h=='<':q=q-1
	if h=='.':o=o+chr(l[q])
	if h=='[':t=t+[p]
	if h==']':
		if len(t)==0:
			print e
			f=0
		if l[q]==0:t.pop(-1)
		else:p=t[-1]
	p=p+1
print len(t)!=0 and e or o

