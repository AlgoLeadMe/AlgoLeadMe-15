#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<bool> dp(n + 1);
    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    dp[4] = true;
    for(int i = 5; i <= n; i++)
    {
        if(!dp[i - 4] || !dp[i - 3] || !dp[i - 1])
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }

    if(dp[n])
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
    return 0;
}
