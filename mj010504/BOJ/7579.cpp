#include <bits/stdc++.h>

using namespace std;

int main() {

   // freopen("input.txt", "rt", stdin);  
    int n, m; cin >> n >> m;

    vector<int> active(n);
    for(int i = 0; i < n; i++) cin >> active[i];

    vector<int> cost(n);
    for(int i = 0; i < n; i++) cin >> cost[i];

    int maxx = 0; // 최대 메모리 공간
    for(int i = 0; i < n; i++) {
        maxx += active[i];
    }

    vector<int> dp(maxx + 1, 2147900); 
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = maxx; j >= active[i]; j--) { // downTo 방식을 사용하여 중복 제거
        dp[j] = min(dp[j], dp[j - active[i]] + cost[i]);
      }
    }

    int res = INT_MAX;
    for(int i = m; i <= maxx; i++) {
      res = min(res, dp[i]);
    }

    cout << res;    

    return 0;
}
