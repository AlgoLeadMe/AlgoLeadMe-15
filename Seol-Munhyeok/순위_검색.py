from collections import defaultdict
from bisect import bisect_left

def make_keys(field):
    # 입력된 필드에 대해서 '-'가 포함된 모든 경우를 keys에 저장
    keys = []
    lang, pos, career, food = field
    for a in [lang, '-']:
        for b in [pos, '-']:
            for c in [career, '-']:
                for d in [food, '-']:
                    keys.append((a, b, c, d))
    
    return keys

def solution(info, query):
    db = defaultdict(list)

    # info에서 field와 score를 분리한다.
    for i in info:
        s = i.split()
        field = s[:4]
        score = int(s[4])
        keys = make_keys(field)
        for key in keys:
            db[key].append(score)
    
    # 이진 탐색을 하기 위해 점수를 정렬한다.
    for key in db:
        db[key].sort()

    # query를 처리한다.
    answer = []
    for q in query:
        s = q.replace(" and ", " ").split()
        field = tuple(s[:4])
        scores = db.get(field, [])
        score = int(s[4])

        # 이진 탐색으로 해당 field에서 점수가 score 이상인 사람의 수를 구한다.
        idx = bisect_left(scores, score)
        answer.append(len(scores) - idx)

    return answer