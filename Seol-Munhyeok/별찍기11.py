n = int(input())
n //= 3

res=['  *  ',
     ' * * ',
     '*****']

space = 3
while n != 1:
    lines = res
    res = []

    # 위쪽 삼각형: 기존 삼각형을 가운데 정렬
    for i in lines:
        res.append(' ' * space + i + ' ' * space)
    
    # 아래쪽 삼각형: 기존 삼각형을 좌우로 붙임
    for j in lines:
        res.append(j + ' ' + j)
    
    n //= 2
    space *= 2

print('\n'.join(res))