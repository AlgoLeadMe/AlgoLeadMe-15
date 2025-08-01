#include <bits/stdc++.h>
using namespace std;

vector<bool> visited; // 출력 인덱스 사용 여부 검사용

void func(string tmp, int startidx, int endidx)
{
    if(startidx > endidx)
    {
        return;
    }
    int minidx = startidx; // 가장 사전순으로 앞서는 문자의 인덱스, startidx로 초기화
    for(int i = startidx; i <= endidx; i++)
    {
        if(tmp[minidx] > tmp[i])
        {
            minidx = i; // 범위 내에서 가장 사전순으로 앞서는 문자 찾기
        }
    }
    visited[minidx] = true;
    for(int i = 0; i < tmp.length(); i++)
    {
        if(visited[i])
        {
            cout << tmp[i];
        }
    }
    cout << "\n";

    func(tmp,minidx + 1,endidx); // 뒤쪽부터 탐색
    func(tmp,startidx,minidx - 1); // 앞쪽 탐색
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    string tmp;
    cin >> tmp;
    visited.resize(tmp.length(),false);
    func(tmp,0,tmp.length() - 1);
    return 0;   
}
