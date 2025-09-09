#include <iostream>   
#include <vector>     
#include <algorithm>  

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long window_sum = 0;

    for (int i = 0; i < K; i++) {
        window_sum += a[i];
    }

    long long max_sum = window_sum;

    for (int i = K; i < N; i++) {
        window_sum += a[i];
        window_sum -= a[i - K];
        max_sum = max(max_sum, window_sum);
    }

    cout << max_sum << endl;
    return 0;
}
