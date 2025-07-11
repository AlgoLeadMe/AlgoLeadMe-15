from collections import Counter
import math

n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]
theta = []

for x, y in points:
    theta.append(math.atan2(y, x))

count = Counter(theta)
print(count.most_common(1)[0][1])
