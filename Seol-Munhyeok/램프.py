import sys
from collections import defaultdict
n, m = map(int, input().split())
a = [list(map(int, input())) for _ in range(n)]
k = int(input())

count = defaultdict(int)
for i in range(n):
    temp = []
    for j in range(m):
        if a[i][j] == 0:
            temp.append(j)
    count[tuple(temp)] += 1

sorted_count = sorted(count.items(), key=lambda x: x[1], reverse=True)
for key, v in sorted_count:
    if k >= len(key) and k % 2 == len(key) % 2:
        print(v)
        sys.exit()
print(0)