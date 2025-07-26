#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n; 

    // 끝나는 시간, 시작 시간을 구조체처럼 정의해줌
    vector<pair<int, int>> meetings;  

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        // 종료 시간을 먼저 넣는 이유: 종료 시간 기준으로 정렬할 것이기 때문
        meetings.push_back({ end, start });
    }

    // 종료 시간을 기준으로 오름차순 정렬
    sort(meetings.begin(), meetings.end());

    int count = 0;         
    int current_end = 0;    

    // 회의 목록 순회
    for (const auto& meeting : meetings) {
        int start = meeting.second;
        int end = meeting.first;

        // 현재 회의가 직전 회의 이후에 시작하면 선택 가능
        if (start >= current_end) {
            count++;             
            current_end = end;  
        }
    }

    cout << count << endl; 
    return 0;
}
