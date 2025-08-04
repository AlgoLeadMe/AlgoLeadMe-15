string = input()
n = len(string)
visited = [False] * n

def solution(s, start, end):
    if start > end:
        return
    
    min_idx = start
    for i  in range(start, end + 1):
        if s[min_idx] > s[i]:
            min_idx = i

    visited[min_idx] = True
    print("".join(s[i] for i in range(n) if visited[i]))

    solution(s, min_idx + 1, end)
    solution(s, start, min_idx - 1)

solution(string, 0, n - 1)