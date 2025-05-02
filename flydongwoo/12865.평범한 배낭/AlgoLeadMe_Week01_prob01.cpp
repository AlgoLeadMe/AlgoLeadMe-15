// BOJ 12865�� - ����� �賶
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    // N: ������ ����, K: �賶�� ���� �� �ִ� �ִ� ����
    int N, K;
    cin >> N >> K;

    // i��° ������ ���Ը� ����, i��° ������ ��ġ�� ����
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    // ���� �賶 ���԰� j�� ��, ���� �� �ִ� �ִ� ��ġ
    // ���Դ� 0kg���� Kkg���� �����ϹǷ� K+1��, �ʱⰪ 0���� ����
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        // j--�� ������ ���� ������ ���� �� �ִ� �� ���� ���ؼ���
        for (int j = K; j >= weight[i]; j--) {
            // ������ ���԰� �ɰ� ��ġ�� ������, �ȳ����� �״����
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[K] << endl;

    return 0;
}
