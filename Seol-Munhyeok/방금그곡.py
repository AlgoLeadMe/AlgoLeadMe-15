def time_to_sec(time):
    h, m = time.split(":")
    return 60 * int(h) + int(m)

def convert(score):
    lst = [("B#", "b"), ("C#", "c"), ("D#", "d"), ("E#", "e"), ("F#", "f"), ("G#", "g"), ("A#", "a")]
    for a, b in lst:
        score = score.replace(a, b)        
    return score

def convert_2(score, length):    
    size = len(score)
    if size == length:
        return score
    if size > length:
        return score[:length]
    if size < length:
        return score * (length // size) + score[:length % size]


def solution(m, musicinfos):
    answer = '(None)'
    max_size = -1
    for info in musicinfos:
        start, end, title, score = info.split(",")
        length = time_to_sec(end) - time_to_sec(start)
        m, score = convert(m), convert(score)
        if m in convert_2(score, length) and length > max_size:
            answer = title
            max_size = length
            
    return answer