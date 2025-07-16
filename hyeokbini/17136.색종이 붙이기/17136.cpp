#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
vector<vector<int>> paper(10, vector<int>(10));
vector<int> papercount(6, 0);

void func(int x, int y, int curans)
{
    if(y == 10)
    {
        ans = min(ans,curans);
        return;
    }
    if(x == 10)
    {
        func(0, y + 1, curans);
        return;
    }
    if(paper[x][y] == 0)
    {
        func(x + 1,y,curans);
        return;
    }
    for (int k = 5; k > 0; k--) // 색종이 크기(큰 것부터)
    {
        if (papercount[k] == 5)
        {
            continue;
        }
        bool canmake = true;
        if (x + k > 10 || y + k > 10)
        {
            continue;
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
                    paper[i][j] = 0;
                }
            }
            papercount[k]++;
            func(x + 1, y, curans + 1);
            for (int i = x; i < x + k; i++)
            {
                for (int j = y; j < y + k; j++)
                {
                    paper[i][j] = 1;
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
        cout << 0;
        return 0;
    }
    func(0, 0, 0);
    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
