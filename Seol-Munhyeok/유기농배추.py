import sys
from collections import deque
input = sys.stdin.readline


def solution(arr, m, n, coords):
    visited = [[False for _ in range(m)] for _ in range(n)]
    answer = 0

    def bfs(y, x):
        queue = deque()
        queue.append((y, x))
        visited[y][x] = True
        dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]

        while queue:
            cy, cx = queue.popleft()
            for d in range(4):
                ny, nx = cy + dy[d], cx + dx[d]
                if 0 <= ny < n and 0 <= nx < m:
                    if arr[ny][nx] == 1 and not visited[ny][nx]:
                        visited[ny][nx] = True
                        queue.append((ny, nx))

    for y, x in coords:
        if arr[y][x] == 1 and not visited[y][x]:
            bfs(y, x)
            answer += 1

    return answer
    
    
t = int(input())
for _ in range(t):
    arr = [[0 for _ in range(51)] for _ in range(51)]  # 매번 배열 초기화
    coords = []  # 배추 좌표 저장
    m, n, k = map(int, input().split())
    for _ in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1
        coords.append((y, x))
    print(solution(arr, m, n, coords))



