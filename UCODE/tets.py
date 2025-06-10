import sys
import math
input = sys.stdin.read
data = input().split()
t = int(data[0])
index = 1
results = []
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
for _ in range(t):
    n = int(data[index])
    k = int(data[index + 1])
    index += 2
    if k == 0:
        total = n * (n + 1) // 2
        results.append(str(total))
        continue
    g = 1 << k 
    total = 0
    for i in range(1, n + 1):
        d = gcd(i, g)
        total += i // d
    results.append(str(total))
print('\n'.join(results))
