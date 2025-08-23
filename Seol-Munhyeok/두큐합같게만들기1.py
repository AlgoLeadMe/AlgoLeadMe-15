from collections import deque

def solution(queue1, queue2):
    q1, q2 = deque(queue1), deque(queue2)
    sum1, sum2 = sum(q1), sum(q2)

    if (sum1 + sum2) % 2 == 1:
        return -1
    
    n = len(q1)
    for i in range(4*n+1):
        if sum1 > sum2:
            value = q1.popleft()
            q2.append(value)
            sum1 -= value
            sum2 += value
        elif sum1 < sum2:
            value = q2.popleft()
            q1.append(value)
            sum2 -= value
            sum1 += value
        else:
            return i
        
    return -1
    