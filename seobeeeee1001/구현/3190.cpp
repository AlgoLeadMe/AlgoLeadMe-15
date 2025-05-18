#include<bits/stdc++.h>
using namespace std;
int board[102][102];
deque<pair<int,char>> dir;
deque<pair<int,int>> snake;

//북에서 시계방향
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//이동 칸에 사과(2) -> 사과 없어지고 꼬리 움직이지 않음
// 없으면 몸길이를 줄여서 꼬리 위치 칸 비워줌. (몸길이 고정)


int n,k,L;
int r,c; // (r,c) 현재 위치
int cur_dir = 1; // 오른쪽 방향 


bool move(){
    r += dx[cur_dir];
    c += dy[cur_dir];
    if(r < 0 || c < 0 || r >= n || c >= n) {
        // cout<<"벽";
        return false;
    }
    if(board[r][c] == 1) {
        // cout<<"자기 자신의 몸";
        return false;
    }
    snake.push_front({r,c});
    if(board[r][c] == 2) board[r][c] = 1;
    else if(board[r][c] == 0){
        board[r][c] = 1;
        int tail_x,tail_y;
        tie(tail_x,tail_y) = snake.back();
        snake.pop_back();
        board[tail_x][tail_y] = 0;
    } 
    return true;
}



int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x,y; // 사과 위치
        cin>>x>>y;
        board[x-1][y-1] = 2;
    }
    cin>>L;
    for(int i=0;i<L;i++){
        int x; // x초 후
        char d; // 방향
        cin>>x>>d;
        dir.push_back({x,d});
    }
    snake.push_front({0,0});
    int t = 0;
    while(1){
        t++;
        // cout<<"뱀의 머리 : "<<snake.front().first<<" "<<snake.front().second<<"\n";
        if(!move()){
            cout<<t;
            break;
        }
        int change_time,d;
        tie(change_time,d) = dir.front();
        if(t==change_time){
            dir.pop_front();
            if(d == 'L'){
                cur_dir--;
                if(cur_dir<0) cur_dir = 3;
            }
            if(d=='D'){
                cur_dir++;
                cur_dir = cur_dir % 4;
            }
        }

    }
}