#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct vec{
    int x,y,z;
};

int bfs(vector<vector<vector<int>>> box, int m, int n, int h){
    int x[4] = {0, 1, 0, -1};   //가로 m
    int y[4] = {-1, 0, 1, 0};   //세로 n
    int z[2] = {-1, 1}; //높이
    int max=0; //반환할 날짜
    queue<vec> q;
    //토마토의 최초위치 모두 넣기
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(box[i][j][k]==1){
                    q.push({i,j,k});
                }
            }
        }
    }

    while(!q.empty()){
        auto [_h, _n, _m] = q.front();
        int day = box[_h][_n][_m];
        q.pop();
        for(int i=0;i<6;i++){
            if(i<4){
                int _x = _m+x[i];
                int _y = _n+y[i];
                if(_x>=0 && _x<m && _y>=0 && _y<n && box[_h][_y][_x]==0){
                    q.push({_h,_y,_x});
                    box[_h][_y][_x] = day+1;
                }    
            }else{
                int _z = _h+z[i-4];
                if(_z>=1 && _z<h && box[_z][_n][_m]==0){
                    q.push({_z,_n,_m});
                    box[_z][_n][_m] = day+1;
                }
            }
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(box[i][j][k]==0) return -1;
                if(box[i][j][k]>max) max = box[i][j][k];
            }
        }
    }
    
    return max-1;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, h, cnt_0=0, cnt_1=0;
    cin>>m>>n>>h;
    vector<vector<vector<int>>> box(h, vector<vector<int>>(m, vector<int>(n)));
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                int tmp;
                cin>>tmp;
                if(tmp==0) cnt_0++;
                if(tmp==1) cnt_1++;
                box[i][j][k] = tmp;
            }
        }
    }
    if(cnt_1==0){
        cout<<-1<<"\n";
        return 0;
    }
    if(cnt_0==0 && cnt_1>=1){
        cout<<0<<"\n";
    }
    int res = bfs(box, m, n, h);

    cout<<res<<"\n";
    
    return 0;
}
