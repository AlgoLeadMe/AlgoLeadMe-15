#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
vector<vector<int>> paper(10, vector<int>(10));
vector<int> papercount(6, 0);

void func(int x, int y, int curans)
{
    if(y == 10)
    {
        ans = min(ans,curans); // 모든 행을 탐색했다면 답을 갱신
        return;
    }
    if(x == 10)
    {
        func(0, y + 1, curans); // 한 행을 탐색한다면 다음 행으로
        return;
    }
    if(paper[x][y] == 0)
    {
        func(x + 1,y,curans); // 0인 경우는 탐색하지 않음
        return;
    }
    for (int k = 5; k > 0; k--) // 색종이 크기(큰 것부터)
    {
        if (papercount[k] == 5)
        {
            continue; // 5개 이상 쓴 색종이는 탐색하지 않음
        }
        bool canmake = true;
        if (x + k > 10 || y + k > 10)
        {
            continue; // 범위를 벗어나는 색종이는 탐색하지 않음
        }
        for (int i = x; i < x + k; i++)
        {
            for (int j = y; j < y + k; j++)
            {
                if (!paper[i][j])
                {
                    canmake = false;
                }
            }
        }
        if (canmake)
        {
            for (int i = x; i < x + k; i++)
            {
                for (int j = y; j < y + k; j++)
                {
                    paper[i][j] = 0; // 색종이 덮기
                }
            }
            papercount[k]++;
            func(x + 1, y, curans + 1);
            for (int i = x; i < x + k; i++)
            {
                for (int j = y; j < y + k; j++)
                {
                    paper[i][j] = 1; // 복원
                }
            }
            papercount[k]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    bool hasone = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> paper[i][j];
            if (paper[i][j])
            {
                hasone = true;
            }
        }
    }
    if (!hasone)
    {
        cout << 0; // 1이 없다면 답은 0
        return 0;
    }
    func(0, 0, 0);
    if (ans == INT_MAX)
    {
        cout << -1; // 답이 갱신되지 않았다면 만들 수 있는 경우의 수가 없음
    }
    else
    {
        cout << ans;
    }
    return 0;
}
