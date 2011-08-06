"""
1 2 3
  3 2 1
0 0 0 1 2 3 4 5 0 0 
0 0 0 0 5 4 3 2 1 0 0 0

1 2 3 4 5 6 7 8 9 10
     10 9 8 7 6 5 4 3 2 1
y = 
1 2 3      n 0
0 n n-1 ...  1 0 -> minima in a concave function


1 2 3 ....  n
n n-1 ......1  

1 2 3 ....  n 0
0 0 n n-1 ......1
"""

for i in range(input()):
  x = input()
  if x < 2: print 0
  elif x % 2:
      y = (x-1)/ 2
      print y * y + 1
  else:
      y = (x-2)/2
      print y*(y+1) + 1