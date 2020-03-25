# Consider that 300! is too large to store in C++, which will make the code too complex, I use python this time.
# a[n] = a[0]*a[n-1] + a[1]*a[n-2] + ... + a[n-1]*a[0]

import math

start = 0
a = [0] * 300
a[0] = 1
while True:
    n = int(input())
    if n == 0:
        break

    if a[n] != 0:
        print(a[n] * math.factorial(n))

    else:
        for i in range(start+1, n+1):
            for j in range(i):
                a[i] += a[j] * a[i-j-1]
        start = n
        print(a[n] * math.factorial(n))

 
