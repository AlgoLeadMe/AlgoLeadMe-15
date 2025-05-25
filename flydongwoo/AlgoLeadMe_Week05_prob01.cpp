#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string n;
    cin >> n;

    int count[10] = { 0 };

    for (int i = 0; i < n.length(); i++) {
        int digit = n[i] - '0';
        count[digit]++;
    }

    int hyeokBiniSets = (count[6] + count[9] + 1) / 2;

    int maxCount = 0;
    for (int i = 0; i <= 9; i++) {
        if (i == 6 || i == 9) {
            continue;
        }
        maxCount = max(maxCount, count[i]);
    }

    cout << max(maxCount, hyeokBiniSets) << endl;

    return 0;
}