import sys

T = int(input())

fib = {}
fib[0] = bef2 = 0
fib[1] = bef1 = 1

for i in range(2, 100001):
    val = str(bef2 + bef1)[-21:]  
    fib[val] = i   
    bef2 = bef1  
    bef1 = int(val)

for line in sys.stdin:
    print(fib[line.strip()[-21:]]) 
