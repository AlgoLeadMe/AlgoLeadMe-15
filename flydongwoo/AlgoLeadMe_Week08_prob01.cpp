#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("input1.txt"); 

    int N, M;
    fin >> N >> M;

    set<string> unheard;
    vector<string> result;

    for (int i = 0; i < N; ++i) {
        string name;
        fin >> name;
        unheard.insert(name);
    }

    for (int i = 0; i < M; ++i) {
        string name;
        fin >> name;
        if (unheard.find(name) != unheard.end()) {
            result.push_back(name);
        }
    }

    fin.close();

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (const auto& name : result) {
        cout << name << endl;
    }

    return 0;
}