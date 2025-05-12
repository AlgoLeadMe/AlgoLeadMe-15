// BOJ 1436번 - 영화감독 숌
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

        // temp를 자리수 하나씩 줄여가면서 검사함
        while (temp >= 666) {
            // 끝에 세 자리를 검사함
            if (temp % 1000 == 666) { 
                in666 = true;
                break;
            }
            // 한 자리 줄여서 다시 검사함
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