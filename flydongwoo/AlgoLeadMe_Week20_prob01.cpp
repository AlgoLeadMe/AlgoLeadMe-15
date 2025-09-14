#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<int>line;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		line.push_back(k);
	}
	sort(line.begin(), line.end());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += line[i] * (n - i);
	}
	cout << answer;

}