#include <bits/stdc++.h>
using namespace std;

vector<bool> canuse(10,true);
int ans;
int n;

bool canmake(string strnum)
{
    for(int i = 0; i < strnum.length(); i++)
    {
        // 해당 숫자를 만들 수 없음(번호 고장남)
        if(!canuse[strnum[i] - '0'])
        {
            return false;
        }
    }
    return true;
}

void check(int curnum)
{
    string strnum = to_string(curnum);
    if(canmake(strnum))
    {
        // 번호 누르는데 쓰이는 자릿수 + 목표 번호까지 가는데 쓰이는 +- 버튼 수
        ans = min(ans,abs(curnum - n) + (int)strnum.length());
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int cantuse;
        cin >> cantuse;
        canuse[cantuse] = false;
    }
    // 1. 채널 디폴트값은 100
    if(n == 100)
    {
        cout << 0;
        return 0;
    }
    // 2. 답 디폴트값은 100과 n의 절댓값 차이
    ans = abs(n - 100);
    // 3. 5,6,7,8,9 전부 망가졌다면 최대 탐색은 백만부터 시작해야 함(최악의 경우?)
    for(int i = 0; i <= 1000000; i++)
    {
        check(i);
    }
    cout << ans;
    return 0;
}
