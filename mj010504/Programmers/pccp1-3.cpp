#include<bits/stdc++.h>

using namespace std;

string func(int g, int idx) {
      if(g == 1) {
            return "Rr";
        }
        
        string parent = func(g - 1, idx / 4);

        if(parent == "RR") return "RR";
        else if(parent == "rr") return "rr";
        else {
            int temp = idx % 4;
            if(temp == 0) return "RR";
            else if(temp == 3) return "rr";
            else return "Rr";
        }
    
    
}

vector<string> solution(vector<vector<int>> v) {
    vector<string> res;
    for(int i = 0; i < v.size(); i++) {
        pair<int, int> p = { v[i][0], v[i][1]  - 1};
        res.push_back(func(p.first , p.second));
    }

    return res;
}

