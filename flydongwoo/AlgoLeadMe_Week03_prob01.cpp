// BOJ 1436�� - ��ȭ���� ��
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    int num = 666;

    while (true) {
        int temp = num;
        bool in666 = false;

        // temp�� �ڸ��� �ϳ��� �ٿ����鼭 �˻���
        while (temp >= 666) {
            // ���� �� �ڸ��� �˻���
            if (temp % 1000 == 666) { 
                in666 = true;
                break;
            }
            // �� �ڸ� �ٿ��� �ٽ� �˻���
            temp /= 10; 
        }

        if (in666) {
            count++;
            if (count == N) {
                cout << num << endl;
                break;
            }
        }

        num++;
    }

    return 0;
}