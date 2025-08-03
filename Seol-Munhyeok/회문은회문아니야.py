def solution(word):
    n = len(word)
    if word != word[::-1]:  # 전체가 회문이 아니라면
        return n
    if word.count(word[0]) == n:  # 회문인데 같은 글자로만 구성
        return -1
    return n - 1  # 그 외의 경우

word = input()
print(solution(word))