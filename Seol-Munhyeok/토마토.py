from collections import deque
import sys

m, n = map(int, input().split())
arr = []
dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]
queue = deque()

# 입력 처리, 1인 좌표 저장
for i in range(n):
    row = []
    for j, val in enumerate(map(int, input().split())):
        row.append(val)
        if val == 1:
            queue.append((i, j))
    arr.append(row)

# BFS
while queue:
    y, x = queue.popleft()
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and arr[ny][nx] == 0:
            arr[ny][nx] = arr[y][x] + 1
            queue.append((ny, nx))

# 정답 찾기
answer = -1e9
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            print(-1)
            sys.exit()
        if arr[i][j] > answer:
            answer = arr[i][j]
            
print(answer - 1)
