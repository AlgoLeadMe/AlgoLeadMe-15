def get_points(a, r):
    a_point, r_point = 0, 0
    for i in range(11):
        if a[i] == r[i] == 0: continue
        if a[i] >= r[i]:
            a_point += (10 - i)
        else:
            r_point += (10 - i)
    return (a_point, r_point)
 
def get_combinations(n, r, cur):
    # 마지막일 때는 n을 추가
    if r == 1:
        return [cur + [n]]
    
    results = []
    for i in range(n + 1):
        results += get_combinations(n - i, r - 1, cur + [i])
        
    return results
    
    
def solution(n, info):
    answer = []
    max_point = 0
    cands = get_combinations(n, 11, [])
    sorted_cands = sorted(cands, key=lambda x: tuple(x[::-1]), reverse=True)
    
    for cand in sorted_cands:
        a_point, r_point = get_points(info, cand)
        if a_point >= r_point: continue
        
        diff = r_point - a_point
        if  diff > max_point:
            max_point = diff
            answer = cand
    
    return answer if answer else [-1]