def time_to_sec(time_str):
    h, m, s = map(int, time_str.split(":"))
    return h * 3600 + m * 60 + s

def sec_to_time(sec):
    h = sec // 3600
    m = (sec % 3600) // 60
    s = sec % 60
    return f"{h:02}:{m:02}:{s:02}"

def solution(play_time, adv_time, logs):
    TOTAL_SECONDS = 100 * 60 * 60 + 1
    timeline = [ 0 for _ in range(TOTAL_SECONDS + 2)]
    
    # 시작 지점 += 1, 끝 지점 -= 1
    for log in logs:
        sh, sm, ss = map(int, log[:8].split(":"))
        eh, em, es = map(int, log[9:].split(":"))
        start = time_to_sec(log[:8])
        end = time_to_sec(log[9:])
        timeline[start] += 1  # 시작 값 포함
        timeline[end] -= 1  # 끝 값 제외!
        
    # 각 초의 동시 시청자 수 구하기
    for i in range(1, len(timeline)):
        timeline[i] += timeline[i-1]
    
    # 각 초까지의 누적 재생 시간 구하기
    for i in range(1, len(timeline)):
        timeline[i] += timeline[i-1]
        
    # 광고 재생시간 길이 동안의 누적 재생 시간 구하기
    max_time = 0
    answer = 0
    adv = time_to_sec(adv_time)
    play = time_to_sec(play_time)
    
    for start in range(0, play - adv + 1):
        end = start + adv
        if start == 0:
            curr_time = timeline[end-1]
        else:
            curr_time = timeline[end-1] - timeline[start-1]
        if curr_time > max_time:
            max_time = curr_time
            answer = start
        
    return sec_to_time(answer)