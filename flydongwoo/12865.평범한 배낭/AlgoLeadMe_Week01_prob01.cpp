// BOJ 12865번 - 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    // N: 물건의 개수, K: 배낭에 담을 수 있는 최대 무게
    int N, K;
    cin >> N >> K;

    // i번째 물건의 무게를 저장, i번째 물건의 가치를 저장
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    // 현재 배낭 무게가 j일 때, 담을 수 있는 최대 가치
    // 무게는 0kg에서 Kkg까지 가능하므로 K+1개, 초기값 0으로 설정
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        // j--인 이유는 같은 물건을 여러 번 넣는 걸 막기 위해서임
        for (int j = K; j >= weight[i]; j--) {
            // 넣으면 무게가 능고 가치가 증가함, 안넣으면 그대로임
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[K] << endl;

    return 0;
}
