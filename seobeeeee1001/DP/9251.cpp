#include <bits/stdc++.h>
using namespace std;

int tree[502][502];
int d[502][502];
int n;
int mx = -1;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>tree[i][j];
        }
    }
    d[1][1] = tree[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) d[i][j] = d[i-1][j] + tree[i][j];
            else if(j==i) d[i][j] = d[i-1][j-1] + tree[i][j];
            d[i][j] = max(d[i-1][j-1],d[i-1][j]) + tree[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        mx = max(d[n][i],mx);  
    }
    cout<<mx;
}