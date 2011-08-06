notDone = 1
while notDone:
    x, y = map(int, raw_input().split())
    if x == 0: notDone = 0
    else: print(pow(x,y))
