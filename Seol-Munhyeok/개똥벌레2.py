import sys
input = sys.stdin.readline

N, H = map(int, input().split())

# line[i] = 높이 i에서 시작되는 충돌 변화량
line = [0] * H

for t in range(N):
    h = int(input())
    if t % 2 == 0:  # 석순(아래에서 위로 올라옴)
        line[0] += 1
        line[h] -= 1
    else:  # 종유석(위에서 아래로 내려옴)
        line[H - h] += 1

# prefix[y] = 높이 y에서 총 충돌 개수
prefix = [0] * (H + 1)
for i in range(H):
    prefix[i + 1] = prefix[i] + line[i]

prefix = prefix[1:]

print(line)
print(prefix)
best = min(prefix)
way = prefix.count(best)
print(best, way)
