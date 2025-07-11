n = int(input())
stack = [tuple(input().split()) for _ in range(n)]
answer = ''

while stack:
    # 역순으로 살펴보면서 불필요한 undo를 제거
    command, y, z = stack.pop()
    if command == "undo":
        delete_time = int(z) - int(y)
        while stack and int(stack[-1][2]) >= delete_time:
            stack.pop()
    elif command == "type":
        answer += y

# 역순으로 살펴보기 때문에 정답은 역순으로 출력
print(answer[::-1])