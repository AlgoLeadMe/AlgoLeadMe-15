// BOJ 2292�� - ����
#include <iostream>
using namespace std;

int main() {
    // �� ��ȣ ����
    long long N;
    cin >> N;

    // N�� 1�̸� ������ 1���̴� Ư�� ���̽� ó��
    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }

    long long layer = 1; // �����ϴ� ���� - 1��
    long long max_room = 1; // ���� ������ �ִ� �� ��ȣ

    while (max_room < N) {
        // ���⼭ ����� �� int ���� �ʰ��� �� �ֱ⿡ long long ���
        max_room += 6 * layer;
        layer++;
    }

    cout << layer << endl;

    return 0;
}
