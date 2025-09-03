from itertools import permutations

def solution(expression):
    # 토큰 분리
    token = []
    operators = set()
    num = ''
    for e in expression:
        if e.isdigit():
            num += e
        else:
            token.append(int(num))
            token.append(e)
            operators.add(e)
            num = ''
    token.append(int(num))

    max_val = -1
    # 모든 우선 순위 고려
    for ops in permutations(operators):
        temp = token[:]
        # 연산자 우선 순위대로 처리
        for op in ops:
            stack = []
            i = 0
            while i < len(temp):
                if temp[i] == op:
                    val_1 = stack.pop()
                    val_2 = temp[i + 1]
                    if op == '+':
                        stack.append(val_1 + val_2)
                    elif op == '-':
                        stack.append(val_1 - val_2)
                    elif op == '*':
                        stack.append(val_1 * val_2)
                    i += 2
                else:
                    stack.append(temp[i])
                    i += 1
            temp = stack
        max_val = max(max_val, abs(temp[0]))
                           
    return max_val