#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dice;
vector<int> picked;
pair<int, int> maxRate = {0, 0};
vector<int> maxA;
set<set<int>> s;

void getDiceSum(int idx, vector<int> v, vector<int> selected, vector<int>& sv) {
    if(idx == v.size()) {
        int sum = 0;
        for(int i = 0; i < v.size(); i++) {
           sum += dice[v[i]][selected[i]];
        }

        sv.push_back(sum);
    }
    else {
         for(int i = 0; i < 6; i++) {    
            selected.push_back(i);
            getDiceSum(idx + 1, v, selected, sv);
            selected.pop_back();
        }
    }
}

void rollDice(vector<int> a, vector<int> b) {
    vector<int> sumA; getDiceSum(0, a, {}, sumA);
    vector<int> sumB; getDiceSum(0, b, {}, sumB);

    int victoryA = 0;
    int defeatA = 0;

    for(int i = 0; i < sumA.size(); i++) {
        for(int j = 0; j < sumB.size(); j++) {
            if(sumA[i] > sumB[j]) victoryA += 1;
            if(sumA[i] < sumB[j]) defeatA += 1;
        }
    }

    if(victoryA > maxRate.first) {
        maxRate = {victoryA, defeatA};
        maxA = a;
    }

    if(victoryA == maxRate.first && defeatA < maxRate.second) {
        maxRate = {victoryA, defeatA};
        maxA = a;
    }

     if(defeatA > maxRate.first) {
        maxRate = {defeatA, victoryA};
        maxA = b;
    }

    if(defeatA == maxRate.first && victoryA < maxRate.second) {
        maxRate = {defeatA, victoryA};
        maxA = b;
    }

}

void pickDice(int cnt) {
    if(cnt == n / 2) {
        vector<int> a; vector<int> b;
        for(int i = 0; i < n; i++) {
            if(picked[i]) a.push_back(i);
            else b.push_back(i);
        }

        set<int> as(a.begin(), a.end());
        set<int> bs(b.begin(), b.end());

        if(!s.count(as)) {
            rollDice(a, b);
            s.insert(as); s.insert(bs);
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            if(!picked[i]) {
                picked[i] = true;
                pickDice(cnt + 1);
                picked[i] = false;
            }
        }
    }
}


vector<int> solution(vector<vector<int>> dv) {
    n = dv.size();
    dice = dv;
    picked.resize(n, false);
    pickDice(0);

    for(int i = 0; i < maxA.size(); i++) {
        maxA[i]++;
    }

    return maxA;
}
