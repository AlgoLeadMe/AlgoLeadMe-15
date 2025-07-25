def check(str):
    dic = dict()
    i, j = 0, 0
    while j < len(str):
        if str[i] in dic:
            return False
        dic[str[i]] = 1
        while j < len(str) and str[i] == str[j]:
            j += 1
        i = j

    return True


def check2(word):
    visited = [False for _ in range(26)]
    prev = word[0]
    visited[ord(prev) - ord('a')] = True
    for i in range(1, len(word)):
        cur = word[i]
        if prev != cur:
            if visited[ord(cur) - ord('a')]:
                return False
            visited[ord(cur) - ord('a')] = True
        prev = cur
    return True

n = int(input())
answer = 0
for _ in range(n):
    str = input()
    if check2(str):
        answer += 1

print(answer)