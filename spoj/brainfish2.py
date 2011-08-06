f=1
y=""
m=32767
i=0
mem=[]
b=0
for i in range(m):
    mem.append(0)
def brac(c):
    global i
    global y
    global mem
    c2=c
    f=1
    while f==1:
        c2=c2+1
        if y[c2]=='+':
            mem[i]=mem[i]+1
        elif y[c2]=='-':
            mem[i]=mem[i]-1
        elif y[c2]=='>':
            i=i+1
        elif y[c2]=='<':
            i=i-1
        elif y[c2]=='.':
            print mem[i]
        elif y[c2]==',':
            mem[i]=input()
        elif y[c2]=='[':
            brac(c2)
        elif y[c2]==']':
            if mem[i]==0:
                f=0
                c=c2
            else:
                c2=c
# get input
while f:
    try:
        y+=(raw_input().split('%'))[0]
    except EOFError:
        f=0
f=1
c=0
while c < len(y) and f:
    if y[c]=='[':
        b=b+1
    elif y[c]==']':
        b=b-1
    if b<0:
        f=0
    c=c+1
print(b!=0 or f==0)and "COMPILE ERROR" or "proper"
c=0
i=0
while c < len(y):
    if y[c]=='+':
        mem[i]=mem[i]+1
    elif y[c]=='-':
        mem[i]=mem[i]-1
    elif y[c]=='>':
        i=i+1
    elif y[c]=='<':
        i=i-1
    elif y[c]=='.':
        print mem[i]
    elif y[c]==',':
        mem[i]=input(),
    elif y[c]=='[':
        brac(c)
    elif y[c]=='[':
        pass
    c=c+1


