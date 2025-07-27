n = int(input())
lst = list(map(int, input().split()))
answer = ''

# 가장 힘이 센 사람들의 인덱스를 구한다.
max_value = float('-inf')
max_indices = []

for i, v in enumerate(lst):
    if v > max_value:
        max_value = v
        max_indices = [i]
    elif v == max_value:
        max_indices.append(i)

# 가장 힘이 센 사람이 1명이고 위치가 idx일 때,
# idx >= n // 2이면 B팀이 이기고,
# idx < n // 2이면 R팀이 이긴다.
if len(max_indices) == 1:
    if max_indices[0] >= n // 2:
        answer = 'B'
    else:
        answer = 'R'
# 가장 힘이 센 사람이 2명 이상일 때
else:
    i, j = max_indices[0], max_indices[-1]
    B, R = i, n - j - 1
    if i + j == n - 1:
        answer = 'X'
    elif B > R:
        answer = 'B'
    else:
        answer = 'R'
        
print(answer)
