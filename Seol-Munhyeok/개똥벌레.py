from bisect import bisect_left

# 입력 처리
N, H = map(int, input().split())
down, up = [], []
for i in range(N):
    h = int(input())
    if i % 2 == 0:
        down.append(h)
    else:
        up.append(h)

down.sort()
up.sort()

best = int(1e9)  # 파괴해야 하는 장애물의 최솟값
way = 1  # 구간의 수
for h in range(1, H + 1):
    cnt_down = N // 2 - bisect_left(down, h)
    cnt_up = N // 2 - bisect_left(up, H - h + 1)
    cnt = cnt_down + cnt_up
    if best > cnt:
        best = cnt
        way = 1
    elif best == cnt:
        way += 1
        
print(best, way)
