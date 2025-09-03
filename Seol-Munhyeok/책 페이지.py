answer = [0] * 10  # 0~9 각 숫자의 총 등장 횟수를 담을 배열

start = 1  # 왼쪽 포인터: 아직 세지 않은 최소 숫자
end = int(input())    # 오른쪽 포인터: 아직 세지 않은 최대 숫자(입력 N)
ten = 1  # 현재 바라보는 자릿값(일=1, 십=10, 백=100, ...)

# 숫자 n이 지금 바라보는 자릿값(ten=1,10,100,...)에서
# '접두사'로서 기여하는 고정 등장 횟수를 answer에 더한다.
# 예를들어 calc(12345, 1)은 answer[5], answer[4], ... answer[1]에 +1
# +ten을 하는 이유는 현재 자리 아래쪽에는 항상 ten가지(0..ten-1)의 조합이 깔리므로,
# 그 자리의 같은 숫자 d가 블록 안에서 정확히 ten번 등장하기 때문.
def calc(n, ten):
    while n > 0:
        answer[n % 10] += ten
        n //= 10

# 바깥 while 한 바퀴 = 자릿값 'ten' 하나를 완전히 처리
while start <= end:
    # [1] 왼쪽 모서리 정리: start를 '...0'으로 맞출 때까지 개별 처리
    while start % 10 != 0 and start <= end:
        calc(start, ten)
        start += 1
    if start > end: break  # 다 끝나면 종료

    # [2] 오른쪽 모서리 정리: end를 '...9'로 맞출 때까지 개별 처리
    while end % 10 != 9 and start <= end:
        calc(end, ten)
        end -= 1

    # 여기까지 오면 [start, end]는 현재 자리에서
    # 정확히 '...0 ~ ...9'가 반복되는 '완전 주기 구간'이 됨.

    # [3] 가운데 완전 주기 한 번에 더하기
    # cnt = 현재 자리에서 서로 다른 '접두사' 개수
    # (접두사 하나마다 0~9 각 숫자가 하위 ten가지와 결합하므로
    # 각 숫자가 정확히 'ten'번씩 등장)
    cnt = (end // 10) - (start) // 10 + 1
    for d in range(0, 10):
        answer[d] += cnt * ten

    # [4] 한 자리 올림: 현재 자리 처리를 끝냈으니 윗자리로 이동
    start //= 10
    end //= 10
    ten *= 10

# 결과 출력
for d in range(0, 10):
    print(answer[d], end=' ')
