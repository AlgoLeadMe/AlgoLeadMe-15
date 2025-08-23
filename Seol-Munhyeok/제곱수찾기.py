import math 

answer = -1

def is_square(n):
    return math.isqrt(n) ** 2 == n

def brute():
    global answer
    if n == 1 and m == 1:
        return A[0][0] if is_square(int(A[0][0])) else -1
    
    for r0 in range(n):
        for c0 in range(m):
            for dr in range(-(n-1), n):
                for dc in range(-(m-1), m):
                    if dr == 0 and dc == 0:
                        continue
                    r, c = r0, c0
                    num = ""
                    while 0 <= r < n and 0 <= c < m:
                        num += A[r][c]
                        val = int(num)
                        if is_square(val):
                            answer = max(answer, val)
                        r += dr
                        c += dc
    return answer

n, m = map(int, input().split())
A = [list(input()) for _ in range(n)]

print(brute())