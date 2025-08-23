#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ans = -1;

void check(int val)
{
    int root = (int)sqrt(val);
    if (root * root == val && ans < val)
    {
        ans = val;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    // 시작 위치 지정
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 한칸 단위도 체크
            check(arr[i][j]);
            for (int mulx = -n; mulx <= n; mulx++)
            {
                for (int muly = -m; muly <= m; muly++)
                {
                    if (mulx == 0 && muly == 0)
                    {
                        continue;
                    }
                    int curx = i;
                    int cury = j;
                    int tempval = 0;
                    while (curx < n && curx >= 0 && cury < m && cury >= 0)
                    {
                        tempval *= 10;
                        tempval += arr[curx][cury];
                        check(tempval);
                        curx += mulx;
                        cury += muly;
                    }
                }
            }
        }
    }
    cout << ans;
}