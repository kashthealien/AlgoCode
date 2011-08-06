while i in input():
    A = input()
    high = 10000000
    low = 1
    while ( low <= high ):
        sum = (high + low) / 2
        prod = A * sum + 1
