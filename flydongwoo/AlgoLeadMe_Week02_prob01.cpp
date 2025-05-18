// BOJ 2292번 - 벌집
#include <iostream>
using namespace std;

int main() {
    // 방 번호 저장
    long long N;
    cin >> N;

    // N이 1이면 무조건 1층이니 특수 케이스 처리
    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }

    long long layer = 1; // 시작하는 층수 - 1층
    long long max_room = 1; // 현재 층까지 최대 방 번호

    while (max_room < N) {
        // 여기서 계산할 때 int 범위 초과할 수 있기에 long long 사용
        max_room += 6 * layer;
        layer++;
    }

    cout << layer << endl;

    return 0;
}
