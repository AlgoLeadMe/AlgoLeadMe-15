n = int(input())
arr = [tuple(map(int, input().split())) for _ in range(n)]
arr.sort(key=lambda x: (x[1], x[0]))
answer = 1
s, e = arr[0]
for i in range(1, n):
    if arr[i][0] >= e:
        answer += 1
        s, e = arr[i]

print(answer)