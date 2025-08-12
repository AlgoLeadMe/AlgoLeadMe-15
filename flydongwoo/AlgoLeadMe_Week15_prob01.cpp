#include <iostream>
using namespace std;

int main() {
    int T;  
    cin >> T;

    int dp[12] = { 0 }; 

    // 아무 것도 선택하지 않는 방법 1가지
    dp[0] = 1;  
    // 1
    dp[1] = 1;  
    // 1+1, 2
    dp[2] = 2;  
    // 1+1+1, 1+2, 2+1, 3
    dp[3] = 4;  

    while (T--) {
        int n;
        cin >> n;

        // Bottom-up DP: 작은 값부터 dp[n]까지 계산
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        cout << dp[n] << endl;
    }
    return 0;
}
