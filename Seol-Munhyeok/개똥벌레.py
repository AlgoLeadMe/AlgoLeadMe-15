# 입력 처리
n, h = map(int, input().split())
down, up = [], []
for i in range(n):
    num = int(input())
    if i % 2 == 0:
        down.append(num)
    else:
        up.append(num)

