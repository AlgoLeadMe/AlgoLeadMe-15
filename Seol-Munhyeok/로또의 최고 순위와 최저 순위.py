def get_rank(my_nums, win_nums):
    my_nums.sort()
    win_nums.sort()
    count = 0
    i = j = 0
    while i < len(my_nums) and j < len(win_nums):
        if my_nums[i] > win_nums[j]:
            j += 1
        elif my_nums[i] < win_nums[j]:
            i += 1
        else:
            count += 1
            i += 1
            j += 1
            
    return count

def solution(lottos, win_nums):
    lottos.sort()
    zero_count = lottos.count(0)
    visible_nums = lottos[zero_count:]
    
    temp = get_rank(visible_nums, win_nums) 
    min_rank = 6 if temp <= 1 else 7 - temp
    temp += zero_count
    max_rank = 6 if temp <= 1 else 7 - temp
    
    return [max_rank, min_rank]