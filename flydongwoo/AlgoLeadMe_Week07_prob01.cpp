#include <iostream>
using namespace std;
#define MAX 100

int main() {
    int n;
    cin >> n;


    int fib[MAX] = { 0, 1 };

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n] << endl;

    return 0;
}