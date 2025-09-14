#include<bits/stdc++.h>

using namespace std;

int solution(vector<string> v) {
    int res = 0;
    int ocnt = 0, xcnt = 0;
    int oBingo = 0, xBingo = 0;
    for(int i = 0; i < 3; i++) {
        auto str = v[i];
        for(int j = 0; j < 3; j++) {
            if(str[j] == 'O') ocnt++;
            if(str[j] == 'X') xcnt++;
        }   
    }

    for(int i = 0; i < 3; i++) {
         if(v[i][0] == v[i][1] && v[i][0] == v[i][2]) {
            if(v[i][0] == 'O') oBingo++;
            if(v[i][0] == 'X') xBingo++;
        }

        if(v[0][i] == v[1][i] && v[0][i] == v[2][i]) {
            if(v[0][i] == 'O') oBingo++;
            if(v[0][i] == 'X') xBingo++;
        }
    }

    if(v[0][0] == v[1][1] && v[0][0] == v[2][2]) {
        if(v[0][0] == 'O') oBingo++;
        if(v[0][0] == 'X') xBingo++;
    }

    if(v[0][2] == v[1][1] && v[1][1] == v[2][0]) {
        if(v[1][1] == 'O') oBingo++;
        if(v[1][1] == 'X') xBingo++;
    }
   

   if(ocnt == xcnt && oBingo == 0) res = 1;
   if(ocnt == xcnt + 1 && xBingo == 0) res = 1;
  
    return res;
}
