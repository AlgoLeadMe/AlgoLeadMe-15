#include<bits/stdc++.h>

using namespace std;

int m;
bool isValid(vector<int> v, vector<vector<int>> q, vector<int> ans) {
    for(int i = 0; i < q.size(); i++) {
        auto tv = q[i];
         int sum = 0;

         int a = 0, b = 0;
        while(a < m &&  b < m) {
            if(v[a] == tv[b]) {
                sum++;
                a++; b++;
            }

            if(v[a] > tv[b]) b++;

            if(v[a] < tv[b]) a++;
        }

  
        if(sum != ans[i]) return false;
    
    }

    return true;
}



int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int res = 0;
    m =  q[0].size();

    for(int a = 1; a <= n  - 4; a++) {
        for(int b = a + 1; b <= n - 3; b++) {
            for(int c = b + 1; c <= n - 2; c++) {
                for(int d = c + 1; d <= n -1; d++) {
                    for(int e = d + 1; e <= n; e++) {
                        vector<int> v = {a, b, c, d, e};
                        if(isValid(v, q, ans)) res++;
                    }
                }
            }
        }
    }

    return res;
}
