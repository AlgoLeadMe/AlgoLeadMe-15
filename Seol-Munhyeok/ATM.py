n = int(input())
lst = list(map(int, input().split()))

lst.sort()
p_sum = [0] * (n + 1)

for i in range(n):
    p_sum[i + 1] = p_sum[i] + lst[i]

print(sum(p_sum))
