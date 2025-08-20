import sys

dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]
_dir = 0
a = [[0 for _ in range(1000)] for _ in range(1000)]

c, r = map(int, input().split())
k = int(input())

if k > c * r:
    print(0)
    sys.exit()

y, x = r-1, 0
num = 1
a[y][x] = num
while num <= c * r:
    if num == k:
        print(x+1, r-y)
        break

    ny, nx = y + dy[_dir], x + dx[_dir]
    if ny >= r or ny < 0 or nx >= c or nx < 0 or a[ny][nx] != 0:
        _dir = (_dir + 1) % 4
        continue
    num += 1
    a[ny][nx] = num
    y, x = ny, nx
