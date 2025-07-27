#include <iostream>
#include <string>

using namespace std;

bool isGroupWord(const string& word) {
    bool visited[26] = { false }; 
    // 직전 문자를 저장하는 곳
    char prev = word[0]; 
    // 첫 문자는 무조건 처음 등장한 문자라는 것!
    visited[prev - 'a'] = true;

    for (int i = 1; i < word.length(); ++i) {
        char current = word[i];
        if (current != prev) {
            // 새로운 문자인데 이미 등장한 적이 있다면 그룹 단어가 아님!
            if (visited[current - 'a']) {
                return false;
            }
            // 처음 등장한 문자를 표시함
            visited[current - 'a'] = true;
        }
        // prev를 현재 문자로 갱신함
        prev = current;
    }
    return true; 
}

int main() {
    int N;
    cin >> N;

    int groupWordCount = 0; 

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        if (isGroupWord(word)) {
            groupWordCount++;
        }
    }

    cout << groupWordCount << endl;

    return 0;
}