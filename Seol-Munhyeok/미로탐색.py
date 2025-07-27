from collections import deque

n, m = map(int, input().split())
grid = [ list(map(int, input().strip())) for _ in range(n) ] 
visited = [ [0 for _ in range(m)] for _ in range(n)]
dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]

queue = deque()
queue.append((0, 0))

while queue:
    y, x = queue.popleft()
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if ny < 0 or nx < 0 or ny >= n or nx >= m \
              or visited[ny][nx] or grid[ny][nx] == 0 :
            continue
        visited[ny][nx] = visited[y][x] + 1
        queue.append((ny, nx))
        

print(visited[n-1][m-1] + 1)
