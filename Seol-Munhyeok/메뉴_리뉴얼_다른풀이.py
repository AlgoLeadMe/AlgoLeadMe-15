from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []

    for c in course:
        order_combinations = []
        for order in orders:
            order_combinations += combinations(sorted(order), c)
        
        most_ordered = Counter(order_combinations).most_common()
        answer += [ k for k, v in most_ordered if v > 1 and v == most_ordered[0][1] ]
        
    return [''.join(v) for v in sorted(answer)]