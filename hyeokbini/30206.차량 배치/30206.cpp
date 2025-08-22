#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;

int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // BFS로 레벨(거리) 계산
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int maxLevel = 0;
    vector<long long> levelCount(n + 1, 0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : arr[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                levelCount[dist[v]]++;
                if (dist[v] > maxLevel)
                {
                    maxLevel = dist[v];
                }
                q.push(v);
            }
        }
    }

    // 1번 노드 선택 여부(2가지) × 각 레벨마다 (선택 안함 + 해당 레벨에서 1개 선택)
    long long ans = 2; // 1번 노드 포함/미포함
    for (int d = 1; d <= maxLevel; d++)
    {
        ans = (ans * ((levelCount[d] + 1) % MOD)) % MOD;
    }

    // 공집합 제외
    ans = (ans - 1 + MOD) % MOD;

    cout << ans;
    return 0;
}
