#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    int n, k, coin;
    cin >> n >> k;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        for(int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k];
    return 0;
}