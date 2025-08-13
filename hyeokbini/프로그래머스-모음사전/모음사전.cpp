#include <string>
#include <vector>

using namespace std;

char arr[5] = {'A','E','I','O','U'};
string checkstring;
int count = -1; // 빈 문자열(제일 초기 상태)에서도 count++가 호출되므로 -1에서 시작해야 함
int answer;

void func(string curword)
{
    // 기저조건 - 길이 5 초과되면 return
    if(curword.length() > 5)
    {
        return;
    }
    
    // 호출될 때마다 카운트 증가
    count++;
    
    if(curword == checkstring)
    {
        answer = count;
        return;
    }
    
    for(int i = 0; i < 5; i++)
    {
        func(curword + arr[i]);
    }
}

int solution(string word) {
    checkstring = word;
    func("");
    return answer;
}