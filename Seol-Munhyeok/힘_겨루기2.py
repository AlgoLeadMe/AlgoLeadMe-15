# 누적합 풀이
n = int(input())
lst = list(map(int, input().split()))

prefix_max = [0 for _ in range(n)]
suffix_max = [0 for _ in range(n)]

# 왼쪽 -> 오른쪽으로 가면서 최댓값을 저장
prefix_max[0] = lst[0]
for i in range(1, n):
    prefix_max[i] = max(prefix_max[i-1], lst[i])

# 오른쪽 -> 왼쪽으로 가면서 최댓값을 저장
suffix_max[n-1] = lst[n-1]
for i in range(n-2, -1, -1):
    suffix_max[i] = max(suffix_max[i+1], lst[i])

r_win = b_win = 0
for i in range(1, n):
    r = prefix_max[i-1]  # 기준선 i에서 R팀의 최대값
    b = suffix_max[i]    # 기준선 i에서 B팀의 최대값

    if r > b:
        r_win += 1
    elif r < b:
        b_win += 1
    
if r_win > b_win:
    print('R')
elif r_win < b_win:
    print('B')
else:
    print('X')

print(prefix_max)
print(suffix_max)