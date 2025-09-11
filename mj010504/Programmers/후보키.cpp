#include<bits/stdc++.h>

using namespace std;
set<vector<int>> s;

bool isMinimal(vector<int> tv) {
    int n  = tv.size();
    for(int i = 0; i < (1 << n); i++) {
        vector<int> ttv;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) ttv.push_back(tv[j]);
            if(s.count(ttv) == 1) return false;
        }

        if(s.count(ttv) == 1) return false;
    }

    return true;
}

int solution(vector<vector<string>> v) {
    int n = v.size();
    int m = v[0].size();


    for(int i = 0; i < (1 << m); i++) {
        vector<int> tv;
        for(int j = 0; j < m; j++) {
            if(i & (1 << j)) {
                tv.push_back(j);
            }
        }

        if(!isMinimal(tv)) continue; // 최소성 만족

        set<vector<string>> ts;
        for(int k = 0; k < n; k++) {
            vector<string> sv;
            for(int l = 0; l < tv.size(); l++) {
                sv.push_back(v[k][tv[l]]);
            }

            ts.insert(sv);
        }

        if(ts.size() == n) { // 유일성 만족
            s.insert(tv);
        }
    }

    return s.size();
}
