def fact(x): return (1 if x==0 else x * fact(x-1))
def C(x,y): return (fact(x)/fact(x-y)/fact(y))

def calc(num, nodes):
	if nodes[num][0] == 0 and nodes[num][1] == 0:
		return 1
	elif nodes[num][0] == 0:
		n = calc(nodes[num][1], nodes);
		return n; 
	elif nodes[num][1] == 0:
		m = calc(nodes[num][0], nodes);
		return m;
	else:
		#print nodes[num][0]
		#print nodes[num][1]
		m = calc(nodes[num][0], nodes);
		n = calc(nodes[num][1], nodes);
		l1 = nodes[ nodes[num][0]][2];
		l2 = nodes[ nodes[num][1]][2];
		result = C(l1+l2,l1 )
		result = result * m * n;
		return result;

for i in range(input()):

	nodes=[]
	for j in range(31):
		nodes.append([0,0,1])

	N = input()
	nodeOrder = raw_input().split()
	for i in range(len(nodeOrder)):	nodeOrder[i] = int(nodeOrder[i])
	root = nodeOrder[0]
	for n in range(1,N):
		temp = nodeOrder[n]
		currNode = root
		while 1:
			nodes[currNode][2] = nodes[currNode][2] + 1
			if(temp > currNode):
				if nodes[currNode][1] == 0:
					nodes[currNode][1] = temp
					break
				else:
					currNode = nodes[currNode][1]
			else:
				if nodes[currNode][0] == 0:
					nodes[currNode][0] = temp
					break
				else:
					currNode = nodes[currNode][0];

	# print nodes
	# Calculate the required result for the root of the tree	
	answer = calc(root, nodes)
	print answer

