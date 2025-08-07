n = int(input())
arr = [int(input()) for _ in range(n)]
arr.sort()

answer = -1e18
for i in range(1, n-2 + 1):
    a, b, c = arr[i-1], arr[i], arr[n-1]
    x, y = arr[i+1], arr[0]
    answer = max(answer, abs(a-2*b+c), abs(x-2*b+y))
print(answer)