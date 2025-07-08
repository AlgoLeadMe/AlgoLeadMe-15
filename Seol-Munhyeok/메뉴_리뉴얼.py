from collections import defaultdict
from itertools import combinations

def solution(orders, course):
    answer = []
    
    for c in course:
        # 매번 count 초기화
        count = defaultdict(int)
        # c개에 해당하는 조합을 orders에서 뽑아서 개수를 저장
        for order in orders:
            keys = combinations(order, c)
            for key in keys:
                key = sorted(key)  # 메뉴 구성은 사전순으로 정렬
                count[''.join(key)] += 1
    
        # 주문 횟수기준 내림차순 정렬
        sorted_items = sorted(count.items(), key=lambda x:x[1], reverse=True)
        if sorted_items:
            max_value = sorted_items[0][1]
        
        for menu, cnt in sorted_items:
            # 최소 2번 이상 주문된 조합만 포함
            if not sorted_items or cnt <= 1 or cnt != max_value:
                break
            answer.append(menu)
            
    return sorted(answer)