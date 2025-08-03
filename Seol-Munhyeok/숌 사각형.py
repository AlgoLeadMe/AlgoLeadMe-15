n, d = map(int, input().split())
arr = [[None for _ in range(n)] for _ in range(n)]
found = False

def is_valid(y, x, value):
    row_inserted, col_inserted = [False for _ in range(d)], [False for _ in range(d)]
    # 행, 열을 살펴보며 이미 사용된 숫자 체크
    for i in range(n):
        if arr[y][i] is not None:
            row_inserted[arr[y][i]] = True
    for i in range(n):
        if arr[i][x] is not None:
            col_inserted[arr[i][x]] = True
    
    # 넣으려는 값을 미리 반영
    row_inserted[value] = True
    col_inserted[value] = True

    # 아직 안 나온 숫자 개수 계산
    missing_row, missing_col = 0, 0
    for i in range(d):
        if not row_inserted[i]:
            missing_row += 1
        if not col_inserted[i]:
            missing_col += 1
    
    # 남은 칸 개수 계산
    row_remained = n - (x + 1)
    col_remained = n - (y + 1)

    return row_remained >= missing_row and col_remained >= missing_col
    
def backtracking(y, x):
    global found
    if found:
        return
    if y >= n:
        # 정답 출력
        for i in range(n):
            for j in range(n):
                print(arr[i][j], end=" ")
            print()
        found = True
        return
    if x >= n:
        backtracking(y+1, 0)
        return
    for num in range(d):
        if is_valid(y, x, num):
            arr[y][x] = num
            backtracking(y, x+1)
            arr[y][x] = None
    
backtracking(0, 0)

