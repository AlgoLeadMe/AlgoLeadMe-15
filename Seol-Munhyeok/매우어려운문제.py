n, m = map(int, input().split())

def solution(n, m):
    if n > m:
        return 0 
    tmp = 1
    for i in range(2, n+1):
        tmp = (tmp * i) % m
    return tmp

print(solution(n, m))

